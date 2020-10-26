I = imread('skull.jpg'); %import image 


B=bitget(I,1);  %bitget is used to extract the plane
%logical function convert array element 1 and 0 (i.e true or false)
subplot(2,2,1);imshow(logical(B));title('Bit plane 1'); 

B=bitget(I,2);
subplot(2,2,2);imshow(logical(B));title('Bit plane 2');

B=bitget(I,3);
subplot(2,2,3);imshow(logical(B));title('Bit plane 3');


B=bitget(I,4);
subplot(2,2,4);imshow(logical(B));title('Bit plane 4');


%image reconstruction using different plane
 A=imread('skull.jpg');
 B=zeros(size(A));
 B=bitset(B,7,bitget(A,7));
 B=bitset(B,8,bitget(A,8));
 B=uint8(B);
 figure;
 subplot(1,2,1);
 imshow(B);
 title("combining 8 and 7 bit plane");
 
 B=zeros(size(A));
B=bitset(B,8,bitget(A,8));
B=bitset(B,7,bitget(A,7));
B=bitset(B,6,bitget(A,6));
B=bitset(B,5,bitget(A,5));
B=uint8(B);
 subplot(1,2,2);
 imshow(B);
 title("combining 8,7,6 and 5 bit planes");

