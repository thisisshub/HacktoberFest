#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b,int n,int m){
if(n==0||m==0)
    return 0;
if(a[n-1]==b[n-1])
    return lcs(a,b,n-1,m-1)+1;
else
    return max(lcs(a,b,n,m-1),lcs(a,b,n-1,m));
}

int main(){
int n,m;
string a,b;
cin>>a;
cin>>b;
n=a.length();
m=b.length();
cout<<lcs(a,b,n,m);
}
