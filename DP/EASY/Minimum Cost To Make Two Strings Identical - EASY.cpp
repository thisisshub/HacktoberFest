/*Minimum Cost To Make Two Strings Identical 

Easy Accuracy: 72.91% Submissions: 3072 Points: 2
Given two strings X and Y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

Example 1:

Input: X = "abcd", Y = "acdb", costX = 10 
       costY = 20.
Output: 30
Explanation: For Making both strings 
identical we have to delete character 
'b' from both the string, hence cost 
will be = 10 + 20 = 30.
Example 2:

Input : X = "ef", Y = "gh", costX = 10
        costY = 20.
Output: 60
Explanation: For making both strings 
identical, we have to delete 2-2 
characters from both the strings, hence 
cost will be = 10 + 10 + 20 + 20 = 60.
Your Task:
You don't need to read or print anything. Your task is to complete the function findMinCost() which takes both strings and the costs as input parameters and returns the minimum cost.

Expected Time Complexity: O(|X|*|Y|)
Expected Space Complexity: O(|X|*|Y|)

Constraints:
1 = |X|, |Y| = 1000 */

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    int n1=X.length(),n2=Y.length();
	    int dp[n1+1][n2+1];
	    for(int i=0;i<=n1;i++)
	     for(int j=0;j<=n2;j++){
	         if(i==0||j==0)
	          dp[i][j]=0;
	         else if(X[i-1]==Y[j-1])
	          dp[i][j]=1+dp[i-1][j-1];
	         else
	          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	     }
	     return costX*(n1-dp[n1][n2])+costY*(n2-dp[n1][n2]);
	}
  

};
	

// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
