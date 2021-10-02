/*Nth Fibonacci Number 

Easy Accuracy: 41.85% Submissions: 36605 Points: 2
Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Example 1:

Input: n = 2
Output: 1 
Explanation: 1 is the 2nd number
of fibonacci series.
Example 2:

Input: n = 5
Output: 5
Explanation: 5 is the 5th number
of fibonacci series.

Your Task:  
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1<= n <=1000 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1];
        a[0]=0;
        a[1]=1;
        for(ll i=2;i<=n;i++)
        {
            a[i]=((a[i-1]%1000000007)+(a[i-2]%1000000007))%1000000007;
        }
        cout<<a[n]<<endl;
    }
}


