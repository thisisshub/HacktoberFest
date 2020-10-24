#include<iostream>

using namespace std;

int main()
{
    int n,a=0;

    cout<<"Enter the number which you want to check";
    cin>>n;
     for (int i = 1; i<=n; i++)
     {
         if(n%i==0)
         {
            a+=i;
             
         }
     }
     if (2*n==a)
     {
         cout<<"it is a perfect number";
     }
     else
     {
         cout<<"it is not a perfect number";
     }
  return 0;
}
