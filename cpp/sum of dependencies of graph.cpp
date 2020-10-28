/*
Sum of dependencies in a graph 
Given a directed graph with n nodes. If there is an edge from u to v then u depends on v. Our task is to find out the sum of dependencies for every node.

Example:
For the graph in diagram, A depends on C and D i.e. 2, B depends on D i.e. 1, C depends on D i.e. 1
and D depends on none.
Hence answer -> 0 + 1 + 1 + 2 = 4

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two integers N and E denoting the no of vertices and edges of the graph. Then in the next line are E pairs u and v denoting an edge from u to v.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
2<=N<=150

1<=E<=150

Example:
Input:
2
4 4 
0 2 0 3 1 3 2 3
4 3 
0 2 0 1 0 3
Output:
4
3
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
void addedge(int a,int b){
    g[a].push_back(b);
   // g[b].push_back(a);
}
int find(int n){
    int sum=0;
    for(auto i=0;i<n;i++)
     sum+=g[i].size();
    return sum;
}
int main() {
	//code
	int t,n,m,a,b;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    g.assign(n,vector<int>());
	    for(int i=0;i<m;i++)
	    {
	        cin>>a>>b;
	        addedge(a,b);
	    }
	    cout<<find(n)<<endl;
	}
	return 0;
}
