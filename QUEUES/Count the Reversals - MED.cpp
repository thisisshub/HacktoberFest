/*
Count the Reversals 

Medium Accuracy: 50.95% Submissions: 10421 Points: 4
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the 
string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
​Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countRev() which takes the string S as input parameter and 
returns the minimum number of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 = |S| = 105

 
*/

#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s){
    int ans = 0;
    if(s.size()&1) return -1;
    int cnt = 0;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '{'){
            cnt++;
        }
        else{
            if(!cnt){
                ans++;
                cnt++;
            }
            else{
                cnt--;
            }
        }
    }
    return ans + cnt/2;
}
