I = imread('RONALDO.jpg');  %add your image file

R = I(:,:,1);   %extract RGB
G = I(:,:,2);
B = I(:,:,3);

grey_img = (R*0.2989)+(G*.5870)+(B*0.114);  %change intensity of RGB so that the image become grey

subplot(1,2,1);    %plot figure in 1st row and 1st column in 1x2 matrix
imshow(I);    %Image display
title('Color image');  %title of image
subplot(1,2,2);  %plot figure in 1st row 2nd column
imshow(grey_img);%Image display
title('grey image');%title of image