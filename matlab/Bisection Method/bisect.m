function [x1,err,fx1, k]=bisect(f,a,b,delta)
% Input - f is the function input as a string ’f’
% a and b are the left and right endpoints
% fa and fb are f(a) and f(b) respectively
% fa and fb must have opposite signs
% delta is the tolerance
% Output - x1 is the approximate root
% fx1=f(x1)
% err is the error estimate for c
% k is the current iteration number
 
 
fa=feval(f,a);
fb=feval(f,b);

 
if fa*fb>0
    error('Choose a and b value correctly. Programe exiting......')
end
 

N=1+round((log(b-a)-log(delta))/log(2));
 
for k=1:N
    x1=(a+b)/2;
    fx1=feval(f,x1);

    if fx1==0
        a=x1;
        b=x1;
    elseif fa*fx1>0
        a=x1;
        fa=fx1;
    else
        b=x1;
        fb=fx1;
    end
    
    if b-a < delta
        break
    end
end

 
x1=(a+b)/2;
err=abs(b-a);
fx1=feval(f,x1);
