#include <iostream>

//doge

using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return(gcd(a,a%b));
}
int main()
{
    int a,b,c;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
