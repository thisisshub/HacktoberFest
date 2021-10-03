#include<bits/stdc++.h>
using namespace std;
//naive approach
void factor(int n)
{
    if(n<=1)
    return ;
//divisors always appears in pairs.So a number n can  be written as multiplication 
//of power of prime factor
 // so we just need to travel from 2 to square root of n.
    for(int i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1)
    cout<<n;
}
//efficient solution :Check for 2 and 3 explicitely so that we save some checks 

int main()
{
    int n;
    cout<<"enter the number ";
    cin>>n;
   factor(n);
return 0;
}