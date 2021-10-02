
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
int i,j;
int dp[n+1][W+1];
for(i=0;i<n+1;i++){
    for(j=0;j<W+1;j++){
        if(i==0||j==0)
            dp[i][j]=0;
        else if(wt[i-1]<=j)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        else
            dp[i][j]=dp[i-1][j];
    }
}
return dp[n][W];
}

int main()
{
    int val[] = { 1,4,5,7};
    int wt[] = { 1,3,4,5};
    int W = 7;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}

