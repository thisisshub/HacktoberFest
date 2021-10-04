#include<bits/stdc++.h>
using namespace std;

//This is the naive approach 

/*int lcm(int a, int b)
{
    int res = max(a,b);
    while(true)
    {
        if(res%a == 0 && res%b == 0)
            return res;
        res++;    
    }
return res;
}*/

//efficient solution 
// lcm = (a*b)/gcd
//a*b = gcd(a,b)*lcm(a,b)
int gcd(int a, int b)
{
    if(b==0)
    return a;

return gcd(b,a%b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a, b;
    cout<<"enter two numbers ";
    cin>>a>>b;
    cout<<lcm(a,b);
return 0;
}
