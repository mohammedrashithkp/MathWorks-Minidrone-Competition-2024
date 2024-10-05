% function new_angle = calculateDirection(lines_detect)
%     persistent angle;
%     new_angle = 0.00;
%     if isempty(angle)
%         angle = 0; % initialization
%     else
%         % Finding line with max red detected
%         max_line_val = 0;
% 
%         % Multiple lines will have max. red detect so we need to store
%         % which all lines have max values
%         max_line_nums = zeros(1,8); 
%         for i = 1:8
%             if lines_detect(i) == max_line_val
%                 max_line_nums(i) = 1;
%             elseif lines_detect(i) > max_line_val
%                 max_line_val = lines_detect(i); % !I THINK WE ARE NOT USING THIS
%                 max_line_nums = zeros(1,8); % We need to clear max_line_nums since none of the indices stored here are max now.
%                 max_line_nums(i) = 1;
%             end
%         end
% 
%         angle = mod(angle, 360); % Goes to 360 and comes back. eg: 400 will give 40
%         line_angles = [0, 45, 90, 135, 180, 225, 270, 315];
% 
%         smallest_diff = 360; 
%         closest_line = 1;
% 
%         % This is to find the line which is closest to the previous angle 
%         for i = 1:8
%             if abs(line_angles(i)-angle) < smallest_diff
%                 closest_line = i;
%                 smallest_diff = abs(line_angles(i) - angle);
%             end
%         end
% 
%         % I basically made it so that it chooses the line which is closest
%         % to the angle in which it was going earlier. I think I did this so
%         % it won't back on it's path but this is also probably why it is
%         % not able to go over acute angles. 
%         % !!! so we need to some better idea here
%         least_diff = 8;
%         num_with_least_diff = 1;
%         if nnz(max_line_nums) > 1 % if there are multiple lines with max detected
%             for i = 1:8
%                 if max_line_nums(i) == 1
%                     diff = min(mod(i-closest_line, 8),mod(closest_line-i,8)); % cyclic diff. given by chatgpt. forward ur questions to chatgpt. 
%                     if diff < least_diff 
%                         least_diff = diff; 
%                         num_with_least_diff = i; 
%                     end
%                 end
%             end
%         end
% 
%         % Finding the adjacent line indices 
%         % eg: if line 1, adjacent are 2 and 8
%         next_line_num = num_with_least_diff + 1;
%         if next_line_num > 8
%             next_line_num = 1;
%         end
%         prev_line_num = num_with_least_diff - 1;
%         if prev_line_num < 1
%             prev_line_num = 8;
%         end
% 
%         % Idk if this is the correct way of determining the correct angle.
%         % But i think it works 
%         positive_angle_change_factor = lines_detect(next_line_num)/15;
%         negative_angle_change_factor = lines_detect(prev_line_num)/15;
%         init_angle = 45*(num_with_least_diff-1); % Angle with max detected
%         angle = init_angle + 45*positive_angle_change_factor - 45*negative_angle_change_factor;
%         new_angle = angle;
%     end
% end
function new_angle = calculateDirection(lines_detect)
    persistent angle;
    new_angle = 0.00;
    if isempty(angle)
        angle = 0; % initialization
    else
        % Finding line with max red detected
        max_line_val = 0;

        % Multiple lines will have max. red detect so we need to store
        % which all lines have max values
        max_line_nums = zeros(1,8); 
        for i = 1:8
            if lines_detect(i) == max_line_val
                max_line_nums(i) = 1;
            elseif lines_detect(i) > max_line_val
                max_line_val = lines_detect(i); 
                max_line_nums = zeros(1,8); 
                max_line_nums(i) = 1;
            end
        end

        angle = mod(angle, 360); % Goes to 360 and comes back. eg: 400 will give 40
        line_angles = [0, 45, 90, 135, 180, 225, 270, 315];

        % Find the line with the maximum red detection
        max_line_nums = find(max_line_nums == 1);

        % If there are multiple lines with maximum red detection, choose the one that is most opposite to the previous direction
        if length(max_line_nums) > 1
            prev_angle = angle;
            min_diff = 360;
            best_line_num = max_line_nums(1);
            for i = 1:length(max_line_nums)
                diff = min(mod(line_angles(max_line_nums(i)) - prev_angle, 360), mod(prev_angle - line_angles(max_line_nums(i)), 360));
                if diff < min_diff
                    min_diff = diff;
                    best_line_num = max_line_nums(i);
                end
            end
            max_line_num = best_line_num;
        else
            max_line_num = max_line_nums(1);
        end

        % Calculate the new angle based on the maximum red detection line
        init_angle = 45*(max_line_num-1); % Angle with max detected
        angle = init_angle;

        % Adjust the angle based on the detection values of the adjacent lines
        next_line_num = max_line_num + 1;
        if next_line_num > 8
            next_line_num = 1;
        end
        prev_line_num = max_line_num - 1;
        if prev_line_num < 1
            prev_line_num = 8;
        end
        positive_angle_change_factor = lines_detect(next_line_num)/15;
        negative_angle_change_factor = lines_detect(prev_line_num)/15;
        angle = angle + 45*positive_angle_change_factor - 45*negative_angle_change_factor;

        new_angle = angle;
    end
end
