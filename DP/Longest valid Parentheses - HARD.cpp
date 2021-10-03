/*
Longest valid Parentheses 

Hard Accuracy: 48.35% Submissions: 11616 Points: 8
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Example 1:

Input: S = ((()
Output: 2
Explaination: The longest valid 
parenthesis substring is "()".
Example 2:

Input: S = )()())
Output: 4
Explaination: The longest valid 
parenthesis substring is "()()".
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxLength() which takes string S as input parameter and returns
 the length of the maximum valid parenthesis substring.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 = |S| = 105  
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        // code here
         int n = S.length();

    // Create a stack and push -1 as 
    // initial index to it.
    stack<int> stk;
    stk.push(-1);

    // Initialize result
    int result = 0;

    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (S[i] == '(')
            stk.push(i);
        
        // If closing bracket, i.e.,str[i] = ')'
        else 
        {
            // Pop the previous opening
            // bracket's index
            if (!stk.empty()) 
            {
                stk.pop();
            }
            
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());

            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }

    return result;

    }
   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
