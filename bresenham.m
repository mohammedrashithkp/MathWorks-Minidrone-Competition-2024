% x y was interchanged in the arguments since in matlab indexing of the
% points is (y,x)
function points = bresenham(y1, x1, y2, x2)
    % Initialize variables
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    
    % Determine the direction of the increment
    sx = sign(x2 - x1);
    sy = sign(y2 - y1);

    num_points = max(dx, dy) + 1;
    points = zeros(num_points, 2);
    
    % Initialize the error term
    err = dx - dy;
    
    % Initialize the output points array
    points = [x1, y1];
    
    while ~(x1 == x2 && y1 == y2)
        e2 = 2 * err;
        
        if e2 > -dy
            err = err - dy;
            x1 = x1 + sx;
        end
        
        if e2 < dx
            err = err + dx;
            y1 = y1 + sy;
        end
        
        points = [points; x1, y1]; % Append the new point
    end
end
