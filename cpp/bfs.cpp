//bfs

#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    queue<int> q; 

	q.push(s); 
	vis[s] = true; 

	while (!q.empty()) { 

		int f = q.front(); 
		q.pop(); 

		cout << f << " "; 

	
		for (auto i = adj[f].begin(); i != adj[f].end(); i++) { 
			if (!vis[*i]) { 
				q.push(*i); 
				vis[*i] = true; 
			} 
		} 
	}
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

