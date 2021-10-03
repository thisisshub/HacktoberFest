/*
Minimum number of deletions. 

Easy Accuracy: 79.82% Submissions: 1148 Points: 2
Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.

Example 1:

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".
â€‹Example 2:

Input: n = 3, str = "aba"
Output: 0
Explanation: We don't remove any
character.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minDeletions() which takes the string s and length of s as inputs and returns the answer.

Expected Time Complexity: O(|str|2)
Expected Auxiliary Space: O(|str|2)

Constraints:
1 = |str| = 103
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    long long int n;cin>>n;int dp[n+1][n+1];
	    string s,r;cin>>s;
	    r=s;
	    reverse(s.begin(),s.end());
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0||j==0)
	             dp[i][j]=0;
	            else if(s[i-1]==r[j-1])
	             dp[i][j]=1+dp[i-1][j-1];
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    cout<<n-dp[n][n]<<endl;
	}
	return 0;
}
