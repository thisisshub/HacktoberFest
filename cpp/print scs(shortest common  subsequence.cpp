#include<bits/stdc++.h>
using namespace std;

string lcs(string a,string b,int m,int n){
    string s;
    int dp[m+1][n+1];
    int i,j;
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
i=m;j=n;

while(i>0 && j>0){
    if(a[i-1]==b[j-1]){
        s.push_back(a[i-1]);
        i--;j--;
        }
    else
    {
        if(dp[i][j-1]>dp[i-1][j])
    {
        s.push_back(b[j-1]);
        j--;
    }
    else{
        s.push_back(a[i-1]);
        i--;
    }
}
}
while(i>0){
    s.push_back(a[i-1]);
    i--;
}
while(j>0){
    s.push_back(b[j-1]);
    j--;
}
reverse(s.begin(),s.end());
return s;
}

int main(){
int m,n;
string a,b;
cin>>a;
cin>>b;
m=a.length();
n=b.length();
cout<<lcs(a,b,m,n);
}
