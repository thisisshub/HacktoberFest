/*
Caluclate nPr
*/
#include<iostream>
#include<vector>
using namespace std;
int factorial(int num)
{
    if(num<=1)
        return 1;
    else
        return num*factorial(num-1);
}
int main()
{
    int n,r;
    cin>>n>>r;
    cout<<factorial(n)/factorial(n-r)<<endl;  
}
