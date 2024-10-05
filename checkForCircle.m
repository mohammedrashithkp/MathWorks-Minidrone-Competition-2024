function [isCircle, centroidRow, centroidCol, processed_img] = checkForCircle(binaryImage, processed_img)
    [labeledImage, numComponents] = bwlabel(binaryImage);

    isCircle = false;
    centroidRow = 0.00;
    centroidCol = 0.00;

    for k = 1:numComponents
        
        componentArea = sum(labeledImage(:) == k);

        [rows, cols] = find(labeledImage == k);

        centroidRow = mean(rows);
        centroidCol = mean(cols);

        distances = sqrt((rows - centroidRow).^2 + (cols - centroidCol).^2);

        meanDistance = mean(distances);
        stdDistance = std(distances);

        % tolerance = 0.48
        tolerance = 0.47; % Adjust as needed %0.4 before

        if stdDistance / meanDistance < tolerance
            minRow = min(rows);
            maxRow = max(rows);
            minCol = min(cols);
            maxCol = max(cols);

            width = maxCol - minCol + 1;
            height = maxRow - minRow + 1;
            aspectRatio = width / height;
            
            % 1.59 good
            aspectRatioThreshold = 1.3; % Adjust as needed 1.4 before

            componentArea = sum(labeledImage(:) == k);
            fprintf("COMPONENT AREA: %.2f", componentArea);
            fprintf("ASPECT RATIO: %.2f", aspectRatio);
            
            if aspectRatio < aspectRatioThreshold
                if componentArea < 1200 && componentArea > 400
                    isCircle = true;
                    for i = 1:length(rows)
                        processed_img(rows(i), cols(i), 2) = 1;
                    end
                    disp("CIRCLE DETECTEDDDDDD")
                    break; % Stop if a circle is found
                end
            end
        end
    end
end
