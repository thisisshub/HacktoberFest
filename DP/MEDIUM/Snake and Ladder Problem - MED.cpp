/* Snake and Ladder Problem 

Medium Accuracy: 42.6% Submissions: 8641 Points: 4
Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).

You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder. The board looks like the following.

Example 1:

Input:
N = 8
arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 
       17, 4, 19, 7, 27, 1, 21, 9}
Output: 3
Explanation:
The given board is the board shown
in the figure. For the above board 
output will be 3. 
a) For 1st throw get a 2. 
b) For 2nd throw get a 6.
c) For 3rd throw get a 2.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minThrow() which takes N and arr as input parameters and returns the minimum number of throws required to reach the end of the game.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 = N = 10
1 = arr[i] = 30  */

#include<bits/stdc++.h>
using namespace std;
bool inrange(int i,int n,bool*visited)
    {
        return (i<=n && !visited[i]);
    }
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int *ladderboard = new int[31];
	    for(int i=1;i<=30;i++) ladderboard[i] = -1;
	    while(n--)
	    {
	        int a,b;
	        cin >> a >> b;
	        ladderboard[a] = b;
	    }
	    n=30;
	     // linear ladderboard is ready
        // make a visited array 
        bool * visited = new bool[n+1];
        for(int i=1;i<=n;i++) visited[i] = false;
        
        // now we will take a queue and we will store the value
        //(where we go) and the moves to reach that node
        queue<pair<int,int>> q;
        q.push({1,0}); // means we are at position 1
                       // we have taken 0 steps till now
        // we are required to reach at position 36
        visited[1] = true;
        int ans = -1;
        bool found = false;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front.first==n)
            {
                ans = front.second;
                found = true;
                break;
            }
            for(int j=front.first+1;j<=front.first+6;j++)
            {
                if(inrange(j,n,visited))
                {
                    if(ladderboard[j]==-1)
                    {
                        q.push({j,front.second+1});
                        visited[j] = true;
                    }
                    else
                    {
                        q.push({ladderboard[j],front.second+1});
                        visited[j]= true;
                    }
                }
            }
            if(found) break;
        } 
        cout << ans << endl;
	}
}
