/* Longest Common Subsequence 

Medium Accuracy: 49.98% Submissions: 51918 Points: 4
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103 */

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    int dp[x+1][y+1];
    for(int i = 0; i <= x; i++)
     {
        dp[i][0] = 0;
    }
    
    for(int j = 0; j <= y; j++)
    {
        dp[0][j] = 0;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++)
        {
           if(s1[i-1]==s2[j-1])
             dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y];
}

