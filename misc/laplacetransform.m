syms a t
f = exp(-a*t);
laplace(f)
  //ans = 1 /( a + s )
syms s
F = 1/s^2;
ilaplace(F)
  //ans = t
