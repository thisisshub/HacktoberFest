/*
Count the paths 
Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print the count of all paths from given ‘s’ to ‘d’.

Input:
First line consists of T test cases. First line of every test case consists of V and E, denoting the vertices and edges. Second line of every test case consists of 2*E spaced integers denoting the edge between vertices. Third line of every test case consists of S and D.

Output:
Single line output, print the count of all paths from 's' to 'd'.

Constraints:
1<=T<=100
1<=V,E<=10

Example:
Input:
1
4 6
0 1 0 2 0 3 2 0 2 1 1 3
2 3
Output:
3
*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector<int>* arr=new vector<int>[v];
	    int a,b;
	    for(int i=0;i<e;i++){
	        cin>>a>>b;
	        arr[a].push_back(b);
	    }
	    cin>>a>>b;
	    int count=0;
	    bool* vis=new bool[v];
	    queue<int> q;
	    q.push(a);
	    while(!q.empty()){
	        int top=q.front();
	        q.pop();
	        if(top==b){
	            count++;
	            continue;
	        }
	        vis[top]=true;
	        for(int j=0;j<arr[top].size();j++){
	            if(vis[arr[top][j]]==false){
	                q.push(arr[top][j]);
	            }
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
