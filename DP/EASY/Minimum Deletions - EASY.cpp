/*
Minimum Deletions 

Easy Accuracy: 77.83% Submissions: 5020 Points: 2
Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: S = "aebcbda"
Output: 2
Explanation: Remove characters 'e' 
and 'd'.
Example 2:

Input: S = "geeksforgeeks"
Output: 8
Explanation: One of the possible result
string can be "eefee", so answer is 
13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 = |S| = 103
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s,r;
	    cin>>s;r=s;
	    reverse(s.begin(),s.end());
	    int n=s.length();
	    int dp[n+1][n+1];
	    for(int i=0;i<=n;i++)
	     for(int j=0;j<=n;j++)
	      if(i==0||j==0)
	       dp[i][j]=0;
	     else if(r[i-1]==s[j-1])
	     dp[i][j]=1+dp[i-1][j-1];
	     else
	     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	     cout<<n-dp[n][n]<<endl;
	}
	return 0;
}
