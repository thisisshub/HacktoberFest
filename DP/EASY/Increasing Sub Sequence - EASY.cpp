/*
Increasing Sub Sequence
 
Easy Accuracy: 52.25% Submissions: 157 Points: 2
Given a string S which includes characters a, b, c, ..., z. Where value of a=1, b=2, ..., z=26. Now find the length of the largest increasing subsequence in the string.

Note:  Subsequence doesn't require elements to be consecutively increasing.


Example 1:

Input:
S = abcdapzfqh
Output:
6
Explanation:
The length of largest increasing
subsequence is 6. One of the
sequence with max length 6 is
a, b, c, d, p, z.
Example 2:

Input:
S = hkm 
Output:
3
Explanation:
The length of the largest increasing
subsequence is 3. Sequence with max
length 3 is h,k,m

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLength() which take string S as input parameter and returns the length of the longest increasing subsequence.

Expected Time Complexity: O(|S|2) 
Expected Space Complexity: O(|S|)
 

Constraints:
1<=|S|<=1000
*/

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    int i,j,n;
	    string str;
	    cin >> str;
	    n = str.size();
	    int a[n];
	    for(i=0;i<n;i++)
	        a[i] = 1;
	    
	    for(i=1;i<n;i++)
	    {
	        for(j=0;j<i;j++)
	        {
	            if((int)str[j]<(int)str[i] && a[j]+1>a[i])
	                a[i] = a[j]+1;
	        }
	    }
	    
	    cout << *max_element(a, a+n) <<endl;
	}
	return 0;
}
