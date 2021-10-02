#include<bits/stdc++.h>
using namespace std;

int lcs(string a,string b, int m,int n,int dp[1001][1001]){

    if(m==0||n==0)
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    else{
        if(a[m-1]==b[n-1])
            {return dp[m][n]=1+lcs(a,b,m-1,n-1,dp);}
        else
            {return dp[m][n]=max(lcs(a,b,m,n-1,dp),lcs(a,b,m-1,n,dp));}
    }
return dp[m][n];
}

int main()
{
int m,n;
string a;
string b;
cin>>a;
cin>>b;
m=a.length();
n=b.length();
int dp[m+1][1001];
memset(dp,-1,sizeof(dp));
cout<<lcs(a,b,m,n,dp);
}
