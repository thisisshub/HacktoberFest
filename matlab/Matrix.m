M = input("Enter a 3x3 matrix number: ");
%Rank of matrix
A=[ M(1,1:3)/M(1,1); M(2,1:3);M(3,1:3)];
A=[A(1,1:3); A(2,1:3)-A(2,1)*A(1,1:3); A(3,1:3)-A(3,1)*A(1,1:3) ];
A=[A(1,1:3); A(2,1:3)/A(2,2); A(3,1:3) ];
A=[A(1,1:3); A(2,1:3); A(3,1:3)-A(3,2)*A(2,1:3) ];
if A(3,1:3)==0 
    if A(2,1:3)==0
        if A(1,1:3)==0
             rank=0;
        else
            rank=1;
        end
    else
        rank=2;
    end
else
    rank=3;          
end
fprintf("Rank of the Matrix %d \n",rank);
% Eigen Values
I=[1 0 0; 0 1 0; 0 0 1];
syms y;
eVal = solve(det(M-y*I)==0);
fprintf("Eigen values of matrix M is \n");
eval = double(eVal);
disp(eVal);
%EIgen Vectors 
[V,D] = eig(M);
fprintf("Eigen vectors of matrix M is \n");
disp(V);
