//Check if an edge is a bridge in a graph (removal of edge makes the graph disconnected)

void dfs(int u, list<int> adj[], bool visited[]){
    visited[u]=true;
    for(auto i = adj[u].begin(); i!=adj[u].end();i++){
        if(visited[*i]==false){
            dfs(*i, adj, visited);
        }
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    adj[s].remove(e);
    adj[e].remove(s);
    bool visited[V]={false};
    dfs(s, adj, visited);
    if(!visited[e])
    return true;
    return false;
}