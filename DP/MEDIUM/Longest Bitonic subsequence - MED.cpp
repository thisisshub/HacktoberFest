/*
Longest Bitonic subsequence 

Medium Accuracy: 48.55% Submissions: 6676 Points: 4
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first increasing, then decreasing.
 

Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.
Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 = length of array = 200
1 = arr[i] = 1000000
*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size(),l[n],m[n];
	    l[0]=1,m[n-1]=1;
	    for(int i=1;i<n;i++)
	    {l[i]=1;
	     for(int j=0;j<i;j++)
	     if(nums[i]>nums[j] && l[i]<l[j]+1)
	      l[i]=l[j]+1;}
	      for(int i=n-2;i>=0;i--)
	    {m[i]=1;
	     for(int j=n-1;j>i;j--)
	     if(nums[i]>nums[j] && m[i]<m[j]+1)
	      m[i]=m[j]+1;}
	      int max=-1;
	      for(int i=0;i<n;i++)
	      if(max<l[i]+m[i]-1)
	       max=l[i]+m[i]-1;
	   return max;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
