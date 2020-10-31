/*
find nth catalan number
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>catalin(n+1,0);
    catalin[0]=1;
    catalin[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
            catalin[i]=catalin[i]+catalin[j]*catalin[i-j-1];
    }
    cout<<catalin[n]<<endl;
    
}
