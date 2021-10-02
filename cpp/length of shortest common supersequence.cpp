#include<bits/stdc++.h>
using namespace std;

int lcs(string a,string b,int m,int n){
int i,j;
int dp[m+1][n+1];
for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
        if(i==0||j==0)
            dp[i][j]=0;
    }
}
for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
        if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
 return dp[m][n];
}
int main(){
int m,n;
string a,b;
cin>>a;
cin>>b;
m=a.length();
n=b.length();
cout<<m+n-lcs(a,b,m,n);
}
