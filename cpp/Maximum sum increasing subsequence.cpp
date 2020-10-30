/*
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void maxsumincreasing(int a[],int n,int dp[])
{ 
 
for(int i=1;i<n;i++)
{   
     for(int j=0;j<i;j++)
     {
         if(a[i]>a[j])
         dp[i]=max(dp[i],dp[j]+a[i]);
     }
} 
int maxele=dp[0];

for(int i=1;i<n;i++)
maxele=max(maxele,dp[i]);

cout<<maxele;
}


int main() { int t; cin>>t;
while(t--)
{ 
    int n; cin>>n;
   int a[n];int dp[n];

for(int i=0;i<n;i++)
{cin>>a[i];
dp[i]=a[i];
}

maxsumincreasing(a,n,dp);
cout<<endl;   
}
 //code
 return 0;
}
