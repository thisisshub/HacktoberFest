/*
Longest Palindromic Subsequence 

Medium Accuracy: 82.21% Submissions: 3479 Points: 4
Given a String, find the longest palindromic subsequence.


Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.


Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).


Constraints:
1 = |S| = 1000
*/

#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq (string A);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << longestPalinSubseq (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


//User function Template for C++

int longestPalinSubseq (string s)
{
    // your code here
    string r=s;
    reverse(s.begin(),s.end());
    int c=0,n=s.length(),dp[n+1][n+1];
    for(int i=0;i<=n;i++)
     for(int j=0;j<=n;j++)
      if(i==0||j==0)
       dp[i][j]=0;
      else if(s[i-1]==r[j-1])
       dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
     return dp[n][n];
    
}
