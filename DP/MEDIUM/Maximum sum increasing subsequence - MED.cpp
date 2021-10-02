/*
Maximum sum increasing subsequence 

Medium Accuracy: 49.92% Submissions: 24630 Points: 4
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the 
maximum value.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 = N = 103
1 = arr[i] = 105
*/

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
