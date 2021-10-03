/*
Minimum number of deletions to make a sorted sequence 

Easy Accuracy: 49.22% Submissions: 2847 Points: 2
Given an array arr of size N, the task is to remove or delete the minimum number of elements from the array so that when the remaining elements are 
placed in the same sequence order form an increasing sorted sequence.

Example 1:

Input: N = 5, arr[] = {5, 6, 1, 7, 4}
Output: 2
Explanation: Removing 1 and 4
leaves the remaining sequence order as
5 6 7 which is a sorted sequence.
 
Example 2:
Input: N = 3, arr[] = {1, 1, 1}
Output: 2
Explanation: Remove 2 1's


Your Task:  
You don't need to read input or print anything. Complete the function minDeletions() which takes N and array arr as input parameters and returns the 
integer value

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 = N = 103
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
		

	public:
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    int l[n];l[0]=1;
	    for(int i=1;i<n;i++){
	        l[i]=1;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] && l[i]<l[j]+1)
	             l[i]=l[j]+1;
	        }
	    }
	    return n-*max_element(l,l+n);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
