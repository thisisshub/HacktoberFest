void dfs(int node, vvi &adjList, vb &visited)
{
    visited[node] = true;
    for(int x:adjList[node])
    {
        if(visited[x]) continue;
        dfs(x, adjList, visited);
    }
}

