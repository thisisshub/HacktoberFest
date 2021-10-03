/*
LCS of three strings 

Medium Accuracy: 58.69% Submissions: 9494 Points: 4
Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:

Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.
​Example 2:

Input: 
A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence
in all the strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.


Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).


Constraints:
1<=n1, n2, n3<=20


*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m,n3;
	    cin>>n>>m>>n3;
	    string x,y,z;
	    cin>>x>>y>>z;
	    int dp[n+1][m+1][n3+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            for(int k=0;k<=n3;k++){
	                if(i==0||j==0||k==0)
	                dp[i][j][k]=0;
	                else if(x[i-1]==y[j-1] && x[i-1]==z[k-1])
	                 dp[i][j][k]=1+dp[i-1][j-1][k-1];
	                else{
	                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
	  
	                }
	            }
	        }
	    }
	    cout<<dp[n][m][n3]<<endl;
	}
	return 0;
}
