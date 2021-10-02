#include<iostream>
using namespace std;
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int res = fib(n-1)+fib(n-2);
    return res;
}
int main()
{
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<fib(n);
}