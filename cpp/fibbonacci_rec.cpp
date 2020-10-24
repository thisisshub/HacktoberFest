#include<iostream>
using namespace std;

int fib(int x)
{
  if((x==1)||(x==0))
    return(x);
  else
    return(fib(x-1)+fib(x-2));
}
int main()
{
   int x , i=0;
   cin >> x;
   while(i < x)
   {
      cout << " " << fib(i);
      i++;
   }
   return 0;
}
