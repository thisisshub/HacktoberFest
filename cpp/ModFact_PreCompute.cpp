#include <bits/stdc++.h>
define int long long
using namespace std;  
const int mod = 1e9 + 7;
int fact[1000001];
void pre()
{
    fact[0]=0;
    for(int i=1;i<1000001;i++
        fact[i] = ( fact[i-1] * i ) % mod;
}
int32_t main()  
{  
    int i,n,number;
    pre();
    cout<<"Enter the number of queries: ";    
    cin>>number;    
    whike(number--)
    {
        cin>>n;
        cout<<"Factorial of " <<number<<" is: "<<fact[n]<<"\n";
    }
    return 0;  
}  
