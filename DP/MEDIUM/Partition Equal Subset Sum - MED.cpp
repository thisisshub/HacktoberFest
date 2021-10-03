/*
Partition Equal Subset Sum 

Medium Accuracy: 38.0% Submissions: 69121 Points: 4
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as 
input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 = N = 100
1 = arr[i] = 1000
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s=0;
        for(int i=0;i<N;i++)
         s+=arr[i];
        if(s%2!=0)
         return 0;
        else{
            s=s/2;
            bool dp[N+1][s+1];
            for(int i=0;i<=N;i++){
                for(int j=0;j<=s;j++){
                    if(i==0&&j==0)
                     dp[i][j]= true;
                    else if(i==0)
                    dp[i][j]=false;
                    else if(j==0)
                     dp[i][j]=true;
                    else if(j<arr[i-1])
                     dp[i][j]=dp[i-1][j];
                    else{
                        dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                    }
                }
            }
            return dp[N][s];
        }
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
