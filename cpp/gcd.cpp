// We have to find the gcd of two number this concept is used in tiling problem as we need to 
// find the largest square using which we can tile the rectangle

#include<bits/stdc++.h>
using namespace std;
int gcd(int a , int b) 
{
    int res = min(a,b);
    while(res > 0)
    {
        if(a%res ==0 && b%res ==0)
          break;

    res --;      
    }
return res;    
}

// This is a more efficient approach which is also known as euclid's algorithm 
int gcd(int a, int b)
{
    /*
    here we consider that b is less than a. SO gcd(a,b)= gcd(a-b,b)
    this a basic version of the euclid's theoram 
    */
    while(a!=b)
    {
        if(a>b)
           a=a-b;
        else 
            b= b-a;
    }
return a;
}

//More optimized approach of this algo can be
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
        //this sol does not require any comparision of a and b what this sol does is that it 
        // automatically swaps a and b after comparing
}
int main()
{
    int a,b;
    cout<<"enter two number ";
    cin>>a>>b;
    cout<<gcd(a,b);
return 0;    
}