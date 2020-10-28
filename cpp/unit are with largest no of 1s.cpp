/*
Unit Area of largest region of 1's 
Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers n and m. Then in the next line are the n x m inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

*/

#include <bits/stdc++.h>
using namespace std;
int count(int a[][],int n,int m,int c){
    if()
    return c;
    count(a[i-1][j],n,m,c);
     count(a[i-1][j-1],n,m,c);
      count(a[i][j-1],n,m,c);
       count(a[i+1][j-1],n,m,c);
        count(a[i+1][j+1],n,m,c);
         count(a[i+1][j],n,m,c);
}
int main() {
	//code
	int t;
	while(t--){
	    int m,n;vector<int>v;
	    cin>>m>>n;int a[m][n];
	    for(int i=0;i<m;i++)
	     for(int j=0;j<n;j++)
	       cin>>a[i][j];
	   for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++)
	     if(a[i][j])
	     {
	         int c=count(a[i][j],n,m,0);
	         v.push_back(c);
	     }
	   sort(v.begin(),v.end());
	    cout<<v.back();
	}
	return 0;
}
