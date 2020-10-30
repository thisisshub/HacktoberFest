Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :














				PRACTICE
#include <iostream>
using namespace std;


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

				SOLUTION





#include <bits/stdc++.h>
using namespace std;

void getBFSPath(int **graph,int n,int *visited,int sv,int ev)
{
    map<int,int> reachMap;
    queue<int> que;
    que.push(sv);
    visited[sv] = 1;
    bool found = 0;

    while(!que.empty())
    {
        int v = que.front();
        que.pop();

        if(v == ev)
        {
            found = 1;
            break;
        }

        for(int i = 0; i < n; i++)
        {
            if(i == sv)
            {
                continue;
            }
            
            if(graph[v][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                que.push(i);
                reachMap[i] = v;
            }

        }
    }

    // for(auto it:reachMap)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    if(found)
    {
        int v = ev;
        while(v != sv)
        {
            cout<<v<<" ";
            v = reachMap[v];
        }
        cout<<sv;
    }
}


int main() {
    int n,e;
    cin >> n >> e;

    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    int start,end;
    cin >> start >> end;

    int *visited = new int[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    if(start == end)
        cout<< end <<" ";
    
    else
    {
        getBFSPath(graph,n,visited,start,end);
    }

    return 0;
}
