
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int W = 48,n=7;
    int w[n] = {4,12,2,18,15,6,5};
    int v[n] = {25,75,15,95,80,40,35};
    int dp[n+1][W+1];

    // initialising
    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
            dp[i][j] = 0;
    
    // top down upproach
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(w[i-1] <= j)
                dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    // final answer
    cout<<dp[n][W];

}
