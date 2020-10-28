#include <bits/stdc++.h>
using namespace std;

int main() {
//code
int t;
cin>>t;
while(t--)
{ unordered_set<int>us1;
int n,m;
cin>>n>>m;
int a[n],b[m];

for(int i=0;i<n;i++) {cin>>a[i];
us1.insert(a[i]);
}
int i=0,j=0;
for( ;i<m;i++) {cin>>b[i];
if(us1.find(b[i])!=us1.end())
{
j++;
us1.erase(b[i]);
}
}
cout<<j<<"\n"; }
return 0; }
