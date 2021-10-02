/*Maximum Sum Problem 

Easy Accuracy: 71.41% Submissions: 6039 Points: 2
A number n can be broken into three parts n/2, n/3 and n/4 (consider only integer part). Each number obtained in this process can be divided further recursively. Find the maximum sum that can be obtained by summing up the divided parts together.
Note: The maximum sum may be obtained without dividing n also.

 

Example 1:

Input:
n = 12
Output: 13
Explanation: Break n = 12 in three parts
{12/2, 12/3, 12/4} = {6, 4, 3}, now current
sum is = (6 + 4 + 3) = 13. Further breaking 6,
4 and 3 into parts will produce sum less than
or equal to 6, 4 and 3 respectively.

​Example 2:

Input:
n = 24
Output: 27
Explanation: Break n = 24 in three parts
{24/2, 24/3, 24/4} = {12, 8, 6}, now current
sum is = (12 + 8 + 6) = 26 . But recursively
breaking 12 would produce value 13.
So our maximum sum is 13 + 8 + 6 = 27.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxSum() which accepts an integer n and returns the maximum sum.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


Constraints:
1 <= n <= 106 */

#include<bits/stdc++.h>
using namespace std;
int maximum(int a,int b)
{
return a>b?a:b;
}
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int a[n+1]={0};
for(int i=1;i<=n;i++)
{
a[i]=maximum(a[i/2]+a[i/3]+a[i/4],i);

}
cout<<a[n]<<endl; }}


