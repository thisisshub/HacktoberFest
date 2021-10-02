#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
    map<char,list<int>> mp;
    public:

    void add_edge(char a, char b)
    {
        mp[a].push_back(b);
    }

    void Topological_sort()
    {
        unordered_map<char,bool> visited;
        list<char> ordering;
        for(auto x:mp)
        {
            visited[x.first]=false;
        }
        for(auto x:mp)
        {
            if(!visited[x.first])
            {
                dfs_helper(visited,ordering,x.first);
            }
        }
        for(auto node : ordering)
        {
            cout<<node<<" ";
        }
    }

    void dfs_helper(unordered_map<char,bool>& visited, list<char>& ordering, char src)
    {
        visited[src]=true;
        for(auto nbr:mp[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(visited,ordering,nbr);
                visited[nbr]=true;
            }
        }
        ordering.push_front(src);
    }
};

int main()
{
    Graph g;
    g.add_edge('z','x');
    g.add_edge('x','a');
    g.add_edge('x','b');
    g.add_edge('x','c');
    g.add_edge('z','y');
    g.add_edge('y','a');
    g.Topological_sort();
}