#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
    list<int> *l;
    int V;

    public:

    Graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }

    void add_edge(char a, char b)
    {
        l[a].push_back(b);
    }

    void Topological_sort()
    {
        int indegree[V]={0};
        //Calculate the indegree of every node
        for(int i=0;i<V;i++)
        {
            for(int child:l[i])
            {
                indegree[child]++;
            }
        }
        queue<int> q;
        //find nodes with 0 indegree and push them in the queue
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int nbr:l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(1,4);
    g.add_edge(2,3);
    g.add_edge(2,5);
    g.add_edge(3,5);
    g.add_edge(4,5);
    g.Topological_sort();
}