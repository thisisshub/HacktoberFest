/*
Edit Distance 

Medium Accuracy: 49.98% Submissions: 36844 Points: 4
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations 
are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and 
returns the minimum number of operation required to make both strings equal. 


Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)


Constraints:
1 = Length of both strings = 100
Both the strings are in lowercase.
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        //s->t
        //put s in horizontal part, upper part of table
        //put t vertically
        
     
		    int n1=s.length(),n2=t.length();
		    int dp[n1+1][n2+1];
		    for(int i=0;i<=n1;i++){
		        for(int j=0;j<=n2;j++){
		            if(i==0)
		            dp[i][j]=j;
		            else if(j==0)
		            dp[i][j]=i;
		            else if(s[i-1]==t[j-1])
		            dp[i][j]=dp[i-1][j-1];
		            else
		            dp[i][j]=1+std::min(dp[i-1][j],
		            std::min(dp[i-1][j-1],dp[i][j-1]));
		        }
		    }
		    return dp[n1][n2];
		}
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
