/*
Count ways to reach the n'th stair 

Medium Accuracy: 42.67% Submissions: 38795 Points: 4
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
n = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair
and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs
then 1 stair.
Way 5: Climb 1 stair, then 1 stair and
then 2 stairs.
Example 2:

Input:
n = 10
Output: 89 
Explanation: 
There are 89 ways to reach the 10th stair.
Your Task:
Complete the function countWays() which takes the top stair number m as input parameters and returns the answer % 10^9+7.

Expected Time Complexity : O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 = n = 104
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int dp[100001]={0};
void  ans()
{
    dp[1]=1;
    dp[2]=2;
    int i;
    for(i=3;i<=100000;i++)
    dp[i]=(dp[i-1]+dp[i-2])%mod;
    
}
int main()
 {
    int t;
    cin>>t;
    ans();
    while(t--)
    {
        int n;
      cin>>n;
     cout<<dp[n]<<endl;
    }
	return 0;
 }
