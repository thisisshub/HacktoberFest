#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int coins[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    } 
    int amt;
    cin>>amt;

    int *dp=new int[amt+1];
    dp[0]=1; 
    for(int coin :coins)
    {
      for(int i=1;i<amt+1;i++)
      {
        if(i>=coin)
        {
        dp[i]+=dp[i-coin];
        }
      }
    } 
    cout<<dp[amt]<<endl ;
    }
