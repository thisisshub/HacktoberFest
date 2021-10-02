/*
Longest Increasing Subsequence 

Medium Accuracy: 46.69% Submissions: 53844 Points: 4
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest
increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 = N = 105
0 = A[i] = 106
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
   /*    if(n == 0 || n == 1)
        return n;
    int inc[n];
    for(int i = 0; i < n ;i++)
        inc[i] = 1;
    for(int i = 1; i < n ;i ++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
                inc[i] = max(inc[j]+1, inc[i]);
        }
    }
    return *max_element(inc, inc+n);*/
    
vector<int>v;
v.push_back(a[0]);
for(int i=1;i<n;i++) {if(v[v.size()-1]<a[i]) 
v.push_back(a[i]);
else {auto j=lower_bound(v.begin(),v.end(),a[i]); *j=a[i]; } }
return v.size(); }
    
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
