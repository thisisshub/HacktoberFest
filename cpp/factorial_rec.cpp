#include <iostream>

using namespace std;
int fact(int n)
{
    int f=0;
    if(n==1)
        return 1;
    else
        return f=n*fact(n-1);
}
int main()
{
    int a,b;
    cin>>a;
    b=fact(a);
    cout<<b;
    return 0;
}
