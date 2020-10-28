/*
Segregate 0s and 1s 
Given an array of length N consisting of only 0s and 1s in random order. Modify the array to segregate 0s on left side and 1s on the right side of the array.

Example 1:

Input:
N = 5
arr[] = {0, 0, 1, 1, 0}
Output: 0 0 0 1 1

Example 2:

Input:
N = 4
Arr[] = {1, 1, 1, 1}
Output: 1 1 1 1
Explanation: There are no 0 in the given array, 
so the modified array is 1 1 1 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function segregate0and1() which takes arr[] and n as input parameters and modifies arr[] in-place without using any extra memory.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 = N = 107
0 = arri = 1
*/

#include<bits/stdc++.h>
using namespace std;

void print(long long int a[],long long int n){
    for( long long int i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;   
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	   long long int n;
	    cin>>n;
	    long long int a[n];
	    for(long long int i=0;i<n;i++)
	     cin>>a[i];
	    if(n==1)
	     cout<<a[0]<<endl;
	    else{
	       long long int l=0,r=0,temp;
	        while(r<=n){
	            if(a[r]==0)
	             {
	                 temp=a[l];
	                 a[l]=a[r];
	                 a[r]=temp;
	                 l++;r++;
	             }
	             else
	              r++;
	        }
	        print(a,n);
	    }
	}
	return 0;
}
