n= input("Enter the no of complex numbers: ");
%Input Complex Numbers
for i=1:n
    C(i) = input(['Enter complex ' num2str(i) ' number in the form (a+bi): ']);
end
re= zeros(n,1);
im= zeros(n,1);
con= zeros(n,1);
for i=1:n
    re(i)=real(C(i));
    im(i)=imag(C(i));
    con(i)= conj(C(i));
end
fprintf("ReaL Part:\n");
disp(re);
fprintf("Imaginary Part:\n");
disp(im);
fprintf("Conjugate is:\n");
disp(con);
