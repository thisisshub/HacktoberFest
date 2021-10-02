/* Longest Repeating Subsequence 

Easy Accuracy: 50.4% Submissions: 26111 Points: 2
Given a string, find the length of the longest repeating subsequence such that the two subsequences don't have same string character at the same position, i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

 

Example 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".
Example 2:

Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)
 

Constraints:
1 <= |str| <= 103 */

#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;cin>>n;
	    string s,r;
	    cin>>s;
	    r=s;
	    int dp[n+1][n+1];
	    for(int i=0;i<=n;i++)
	     for(int j=0;j<=n;j++)
	     dp[i][j]=0;
	    for(int i=1;i<=n;i++)
	     for(int j=1;j<=n;j++)
	    {
	        if(s[i-1]==r[j-1] && i!=j)
	         dp[i][j]=1+dp[i-1][j-1];
	        else
	        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	    }
	    cout<<dp[n][n]<<endl;
	}
	return 0;
}
