#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    int dp[n][m];
    for(int i=0;i<=max(n,m);i++)
        dp[0][min(i,m)] = dp[min(i,n)][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string p;
    while(n>0 && m>0)
    {
        if(s[n-1]==t[m-1])
        {
            n--;
            m--;
            p = s[n]+p;
        }
        else{
            if(dp[n-1][m] >= dp[n][m-1])
            {
                n--;
                p = s[n]+p;
            }
            else{
                m--;
                p = t[m]+p;
            }
        }
    }
    while(n)
    {
        n--;
        p = s[n]+p;
    }
    while(m)
    {
        m--;
        p = t[m]+p;
    }
    cout<<p;
}
