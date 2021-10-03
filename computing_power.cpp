#include<bits/stdc++.h>
using namespace std;

int power(int x, int n)
{ //Recursive approach
    if(n==0)
    return 1;
    int temp = power(x,n/2);
    temp *=temp;
    if(n%2 == 0)
    return temp;
    else 
    return temp*x;
}

int co_power(int x,int n)
{//Iterative Approach
    int res=1;
    while(n>0)
    {
        if(n%2!=0)
        res= res*x;

        x *=x;
        n= n/2;
    }
return res;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<co_power(x,n);
return 0;    
}