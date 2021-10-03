/*
First negative integer in every window of size k 

Easy Accuracy: 54.27% Submissions: 12446 Points: 2
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its 
size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window 
does not contain a negative integer , then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
1 <= A[i] <= 105
1 <= K <= N
*/


#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
        long long int i=0,j=0;
     queue<long long int>q;
     vector<long long int>v;
     while(j<N){
         if(A[j]<0)
          q.push(A[j]);
         if(j-i+1<k)
          j++;
         else{
             if(q.size()==0)
              v.push_back(0);
             else
             {v.push_back(q.front());
             if(A[i]==q.front())
              q.pop();
         }
         i++;j++;
     }} 
     return v;                                         
 }
