/*
X Total Shapes 
Given N * M string array arr of O's and X's. The task is to find the number of 'X' total shapes.
'X' shape consists of one or more adjacent X's (diagonals not included).

Input:
The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, in a new line print the total X shapes.

Your Task:
Complete Shape function that takes string array arr, n, m as arguments and returns the count of total X shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Expected Time Complexity : O(N*M)
Expected Auxilliary Space : O(1)

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.
*/

#include<bits/stdc+.h>
using namespace std;
#define MAX 50
char graph[MAX][MAX];

bool valid(int rr,int cc,int n,int m)
{
    if (rr>=0 && rr<n &&cc>=0 &&cc<m)
    return true;
    return false;
}

int xshape(char graph[MAX][MAX],vector<vector<int>>& visited,int x,int y,int n,int m)
{
    visited[x][y]=1;
    int dr[]={0,0,1,-1};
    int dc[]={1,-1,0,0};
    for (int i=0;i<4;i++)
    {
        int rr=x+dr[i];
        int cc=y+dc[i];
        if (valid(rr,cc,n,m)&&graph[rr][cc]=='X'&& visited[rr][cc]==-1)
        xshape(graph,visited,rr,cc,n,m);
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        cin>>graph[i][j];
	    }
	    vector<vector<int>>visited(n,vector<int>(m,-1));
	    int res=0;
	    for (int i=0;i<n;i++)
	    {
	        for (int j=0;j<m;j++)
	        {
	            if (visited[i][j]==-1 && graph[i][j]=='X')
	            {
	                xshape(graph,visited,i,j,n,m);
	                res+=1;
	            }
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}
