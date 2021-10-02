#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b, int m,int n){
    int dp[m+1][n+1];
    int i,j;
    int r=0;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0||j==0)
                dp[i][j]=0;
        }
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
                {dp[i][j]=dp[i-1][j-1]+1;
                r=max(r,dp[i][j]);}
            else
                dp[i][j]=0;
        }
    }

    return r;

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
cout<<lcs(a,b,m,n);
}

