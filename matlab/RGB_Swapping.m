I = imread("red.jpg"); %import solid red image 
R = I(:,:,1); 
G = I(:,:,2);
B = I(:,:,3);

subplot(1,2,1);
imshow(I);  %orignal image display
title("red rectangle");

temp =B;   %swap blue and red plane
B =R;
R = temp;

img = cat(3,R,G,B); %concatinate all plane
subplot(1,2,2);
imshow(img);   %display swapped image
title("blue rectangle");