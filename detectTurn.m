function [turn_detected] = detectTurn(mask)
    turn_detected = 0;
    
    % Define rectangle for turn detection
    rect_width = 80;
    rect_height = 60;
    half_width = floor(rect_width/2);
    half_height = floor(rect_height/2);

    [h,w] = size(mask);
    center_y = floor(h/2);
    center_x = floor(w/2);
    
    top_rect_pnts = bresenham(center_x-half_width, center_y-half_height, center_x+half_width, center_y-half_height); % 81x2
    right_rect_pnts = bresenham(center_x+half_width, center_y-half_height, center_x+half_width, center_y+half_height); % 61x2
    bottom_rect_pnts = bresenham(center_x-half_width, center_y+half_height, center_x+half_width, center_y+half_height);
    left_rect_pnts = bresenham(center_x-half_width, center_y-half_height, center_x-half_width, center_y+half_height);
    
    % for only detecting sharp turns 

    top_pnts_detected = zeros(1, rect_width+1);
    right_pnts_detected = zeros(1, rect_height+1);
    bottom_pnts_detected = zeros(1, rect_width+1);
    left_pnts_detected = zeros(1, rect_height+1);

    % Detection in format: [D1ax D1ay D1bx D1by; 
    %                       D2ax D2ay D2bx D2by;
    %                       ...]

    rect_detection = zeros(4,4);
    
    first_point = [0 0];
    last_point = [0 0];
    for i = 1:rect_width+1
        pnt = top_rect_pnts(i,:);
        % processed_img(pnt(1), pnt(2), 3) = 1;
        
        if mask(pnt(1), pnt(2)) == 1
            top_pnts_detected(i) = 1;
            if (first_point == 0)
                first_point = [pnt(1), pnt(2)];
            end
            last_point = [pnt(1), pnt(2)];
            % processed_img(pnt(1), pnt(2), 2) = 1;
        end
    end
    rect_detection(1, :) = [first_point, last_point];

    first_point = [0 0];
    last_point = [0 0];
    for i = 1:rect_height+1
        pnt = right_rect_pnts(i,:);
        % processed_img(pnt(1), pnt(2), 3) = 1;
        if mask(pnt(1), pnt(2)) == 1
            right_pnts_detected(i) = 1;
            if (first_point == 0)
                first_point = [pnt(1), pnt(2)];
            end
            last_point = [pnt(1), pnt(2)];
            % processed_img(pnt(1), pnt(2), 2) = 1;
        end
    end
    rect_detection(2, :) = [first_point, last_point];

    first_point = [0 0];
    last_point = [0 0];
    for i = 1:rect_width+1
        pnt = bottom_rect_pnts(i,:);
        % processed_img(pnt(1), pnt(2), 3) = 1;
        if mask(pnt(1), pnt(2)) == 1
            bottom_pnts_detected(i) = 1;
            if (first_point == 0)
                first_point = [pnt(1), pnt(2)];
            end
            last_point = [pnt(1), pnt(2)];
            % processed_img(pnt(1), pnt(2), 2) = 1;
        end
    end
    rect_detection(3, :) = [first_point, last_point];

    first_point = [0 0];
    last_point = [0 0];
    for i = 1:rect_height+1
        pnt = left_rect_pnts(i,:);
        % processed_img(pnt(1), pnt(2), 3) = 1;
        if mask(pnt(1), pnt(2)) == 1
            left_pnts_detected(i) = 1;
            if (first_point == 0)
                first_point = [pnt(1), pnt(2)];
            end
            last_point = [pnt(1), pnt(2)];
            % processed_img(pnt(1), pnt(2), 2) = 1;
        end
    end
    rect_detection(4, :) = [first_point, last_point];

    % convert to linear format
    linear_rect_detection = [rect_detection(1,:), rect_detection(2,:), circshift(rect_detection(3,:), [0 2]), circshift(rect_detection(4,:),[0 2])];

    % find common points, change them to zero, pop all zeros
 
    for i = 1:2:13
        if linear_rect_detection(i:i+1) == linear_rect_detection(i+2:i+3)
            linear_rect_detection(i:i+3) = 0;
        end
    end
    if linear_rect_detection(15:16) == linear_rect_detection(1:2)
        linear_rect_detection(15:16) = 0;
        linear_rect_detection(1:2) = 0;
    end
    
    final_linear_detection = linear_rect_detection(linear_rect_detection ~= 0); % remove all zeros
    if (linear_rect_detection(15:16) == linear_rect_detection(1:2))
        if (linear_rect_detection(15) == linear_rect_detection(1)) && (linear_rect_detection(16) == linear_rect_detection(2))
            final_linear_detection = circshift(final_linear_detection, [0 2]); % since the points will be at the ends of the linear matrix 
        end
    end

    % TODO: implement something to handle error if there are < 4 values
    % in final_linear_detection

    % getting proper line points
    
    % first track line: x1 y1 -> x2 y2
    % second track line: x3 y3 -> x4 y4
    if size(final_linear_detection) == [1 8]
        first_track_line = [final_linear_detection(1:4)];
        second_track_line = [final_linear_detection(5:8)];
          
        w_actual = 19; % Found by trial 
        w_detected = sqrt((first_track_line(3)-first_track_line(1))^2 + (first_track_line(4)-first_track_line(2))^2);
        w_ratio = max(-1, min(1, w_actual/w_detected)); % to clamp between -1 and 1 so we don't get error

        theta = asin(w_ratio); % in rad
        
        % STATUS: The theta we are getting are not proper in some cases.
        % Like we need cos in same cases.
        % Lot of edge cases
        
        % Extract coordinates for first_track_line
        x1 = first_track_line(1);
        y1 = first_track_line(2);
        x2 = first_track_line(3);
        y2 = first_track_line(4);
        
        % Extract coordinates for second_track_line
        x3 = second_track_line(1);
        y3 = second_track_line(2);
        x4 = second_track_line(3);
        y4 = second_track_line(4);
        
        first_track_line_pnts = bresenham(y1, x1, y2, x2);
        second_track_line_pnts = bresenham(y3, x3, y4, x4);
        
        % processed_img = displayLine(first_track_line_pnts, 2, processed_img);
        % processed_img = displayLine(second_track_line_pnts, 2, processed_img);
        
        % Calculate the center of the first track line
        center_x = (x1 + x2) / 2;
        center_y = (y1 + y2) / 2;
        
        % Calculate the vector of the first line
        dx1 = x2 - x1;
        dy1 = y2 - y1;
        
        % Rotation matrix for 2D counterclockwise rotation
        rotation_matrix_ccw = [cos(theta), -sin(theta); sin(theta), cos(theta)];
        
        % Rotate the vector of the first line counterclockwise
        rotated_vector_ccw = rotation_matrix_ccw * [dx1; dy1];
        
        % Create the new endpoints for counterclockwise rotation
        new_x1_ccw = center_x - rotated_vector_ccw(1) / 2;  % new start x-coordinate after rotation
        new_y1_ccw = center_y - rotated_vector_ccw(2) / 2;  % new start y-coordinate after rotation
        new_x2_ccw = center_x + rotated_vector_ccw(1) / 2;  % new end x-coordinate after rotation
        new_y2_ccw = center_y + rotated_vector_ccw(2) / 2;  % new end y-coordinate after rotation
        
        % Generate the line points for the counterclockwise rotation
        % new_line_ccw = bresenham(floor(new_y1_ccw), floor(new_x1_ccw), floor(new_y2_ccw), floor(new_x2_ccw));
        % processed_img = displayLine(new_line_ccw, 2, processed_img);
        
        % Check for intersection between the rotated line (counterclockwise) and the second_track_line
        [x_intersect_ccw, y_intersect_ccw, ccw_intersection] = findIntersection(new_x1_ccw, new_y1_ccw, new_x2_ccw, new_y2_ccw, x3, y3, x4, y4);
        
        % Check if an intersection was found for counterclockwise rotation
        if ~isempty(x_intersect_ccw) && ~isempty(y_intersect_ccw)
            if x_intersect_ccw(1) >= 2 && x_intersect_ccw(1) < 118 && y_intersect_ccw(1) >= 2 && y_intersect_ccw(1) < 158
                % processed_img(floor(x_intersect_ccw(1))-1:floor(x_intersect_ccw(1))+1, floor(y_intersect_ccw(1))-1:floor(y_intersect_ccw(1))+1, 1) = 1;
            end
            if ccw_intersection == 1
                fprintf("ccw intersection: %.2f %.2f\n", x_intersect_ccw(1), y_intersect_ccw(1));
            end
        end
        
        
        % Now, check for clockwise rotation
        theta_clockwise = -theta;  % negate theta for clockwise rotation
        rotation_matrix_cw = [cos(theta_clockwise), -sin(theta_clockwise); sin(theta_clockwise), cos(theta_clockwise)];
        
        % Rotate the vector of the first line clockwise
        rotated_vector_cw = rotation_matrix_cw * [dx1; dy1];
        
        % Create the new endpoints for clockwise rotation
        new_x1_cw = center_x - rotated_vector_cw(1) / 2;  % new start x-coordinate after rotation
        new_y1_cw = center_y - rotated_vector_cw(2) / 2;  % new start y-coordinate after rotation
        new_x2_cw = center_x + rotated_vector_cw(1) / 2;  % new end x-coordinate after rotation
        new_y2_cw = center_y + rotated_vector_cw(2) / 2;  % new end y-coordinate after rotation
        
        % Generate the line points for the clockwise rotation
        % new_line_cw = bresenham(floor(new_y1_cw), floor(new_x1_cw), floor(new_y2_cw), floor(new_x2_cw));
        % processed_img = displayLine(new_line_cw, 2, processed_img);
        
        % Check for intersection between the rotated line (clockwise) and the second_track_line
        [x_intersect_cw, y_intersect_cw, cw_intersection] = findIntersection(new_x1_cw, new_y1_cw, new_x2_cw, new_y2_cw, x3, y3, x4, y4);
        
        % Check if an intersection was found for clockwise rotation
        if ~isempty(x_intersect_cw) && ~isempty(y_intersect_cw)            
            if x_intersect_cw(1) >= 2 && x_intersect_cw(1) < 118 && y_intersect_cw(1) >= 2 && y_intersect_cw(1) < 158
                % processed_img(floor(x_intersect_cw(1))-1:floor(x_intersect_cw(1))+1, floor(y_intersect_cw(1))-1:floor(y_intersect_cw(1))+1, 1) = 1;
            end
            if cw_intersection == 1
                fprintf("cw intersection: %.2f %.2f\n", x_intersect_cw(1), y_intersect_cw(1));
            end
        end

        if cw_intersection == 0 && ccw_intersection == 0
            turn_detected = 1;
            disp("TURN DETECTED")
        else
            turn_detected = 0;
            disp("NO TURN DETECTED")
       end
    end
end

% function [new_processed_img] = displayLine(linepnts, color, processed_img)
%     new_processed_img = processed_img;
%     for i= 1:size(linepnts,1)
%             pnt = linepnts(i, :);
%             new_processed_img(pnt(1), pnt(2), color) = 1;
%     end
% end

function [xi, yi, proper_intersection] = findIntersection(x1, y1, x2, y2, x3, y3, x4, y4)
    % Solve for intersection using line equations
    denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    proper_intersection = 0;
    
    if denom == 0
        % Lines are parallel, no intersection
        xi = [];
        yi = [];
        return;
    end
    
    % Compute intersection point
    xi = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denom;
    yi = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denom;
   
    
    % Check if the intersection point lies within both line segments
    if all(xi >= min([x3, x4]) & xi <= max([x3, x4]) & ...
            yi >= min([y3, y4]) & yi <= max([y3, y4]))
        proper_intersection = 1;
    end
end

function [first_index, last_index] = find_first_last_detected(pnts_detected)
    first_index = find(pnts_detected, 1, "first");
    if isempty(first_index)
        first_index = 0;
    end
    last_index = find(pnts_detected, 1, "last");
    if isempty(last_index)
        last_index = 0;
    end
end

