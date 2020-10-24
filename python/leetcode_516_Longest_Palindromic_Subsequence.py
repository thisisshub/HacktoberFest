'''
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2

'''

'''
This is a standard problem of Dynamic Programming
1. If the two ends of a string are the same, then they must be included in the longest palindrome subsequence. Otherwise, both ends cannot be included in the longest palindrome subsequence.
2. Therefore,we will use the relation:

    dp[i][j]: the longest palindromic subsequence's length of substring(i, j), here i, j represent left, right indexes in the string
    
    Initialization: dp[i][i] = 1

    Use relation that:
    if s[i] == s[j]:
        dp[i:j] = 2 + dp[i+1][j-1] 
    else:
        dp[i:j] = max(dp[i][j-1],dp[i+1][j])
     
   
    
'''

class Solution:
    '''
    Time Complexity O(n**(2))
    Space Complexity O(n**(2))
    
    
    '''
    def longestPalindromeSubseq(s):
        dp = [[0]*len(s) for _ in range(len(s))]
        #initialization
        for i in range(len(s)):
            dp[i][i] = 1
        
        #subsequence from i to i+1
        for i in range(len(s)-1):
            dp[i][i+1] = 2 if s[i] == s[i+1] else 1
        
        diff = 2
        n = len(s)
        while diff < n:
            i = 0
            j = i + diff
            while j < n and i < n-1:
                if s[i] == s[j]:
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1],dp[i+1][j-1] + 2)
                else:
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1])
                i += 1
                j = i + diff
            diff += 1
        max_out = 1
        
        #choosing the maximum length of subsequence
        for i in range(n):
            max_out = max(dp[i][-1],max_out)
        return max_out

# Driver Code
if __name__ == "__main__":
    s = "bbbab"
    result = Solution.longestPalindromeSubseq(s)
    print("length of longest Substring = ", result)