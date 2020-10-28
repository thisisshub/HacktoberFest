#include<iostream>
#include<math.h>
#include<vector>
#include<utility>
#include<queue>
#include<map>

using namespace std;

struct node 
{
    node *parent;
    node *child;
    node *left;
    node *right;
    int key, degree, vertex;
    bool mark;
};

struct Edge
{
    int src,dest,distance;
};

node* Fibonacci_min = NULL;
int num_nodes = 0;
map<int,node*> find_array;

void fibHeapInsert(int vertex, int dist)
{
    node *x= new node;
    x->key = dist;
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->mark = false;
    x->vertex = vertex;
    find_array[vertex] = x;
    if(Fibonacci_min==NULL)
    {
        x->left = x;
        x->right = x;
        Fibonacci_min = x; 
    }
    else
    {
        x->left = Fibonacci_min->left;
        x->right = Fibonacci_min;
        (Fibonacci_min->left)->right = x;
        Fibonacci_min->left = x;

        if(x->key < Fibonacci_min->key)
            Fibonacci_min = x;
    }
    
    num_nodes++;
}

void fibHeapCreate(int V, int src)
{
    int index = 0;
    while(index<V)
    {
        if(index==src)
            fibHeapInsert(index,0);
        else
            fibHeapInsert(index,INT_MAX);
        index++;
    }

}

node * fibHeapFind(int index)
{
    if(find_array.find(index)==find_array.end())
        return NULL;
    return find_array[index];
}

void fibHeapLink(struct node *y, struct node *x)
{
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    y->parent = x;
    if(x->child==NULL)
    {
        y->left = y;
        y->right = y;
        x->child = y;
    }
    else
    {
        y->right = x->child;
        y->left = (x->child)->left;
        ((x->child)->left)->right = y;
        (x->child)->left = y;
    }
    if(x->right==x)
        Fibonacci_min=x;
    x->degree++; 
    y->mark = false;   
}

void consolidate()
{
    float mid_val = log2((num_nodes*1.0));
    int len = (int) mid_val;
    len++;
    node* A[len];
    for(int i=0;i<len;i++)
        A[i]=NULL;

    node *x = Fibonacci_min;
    node *y;
    node *temp;
    int d;
    do
    {
        d = x->degree;
        while(A[d]!=NULL)
        {
            y = A[d];
            if(y->key<x->key)
            {
                temp=x;
                x=y;
                y=temp;
            }
            if(y==Fibonacci_min)
                Fibonacci_min=x;
            // cout<<".....Linking"<<endl;
            fibHeapLink(y,x);
            A[d]=NULL;
            d++;
        }
        A[d]= x;
        x=x->right;
    } while (x!=Fibonacci_min);

    Fibonacci_min = NULL;

    for(int i=0;i<len;i++)
    {
        if(A[i]!=NULL)
        {
            if(Fibonacci_min==NULL)
            {
                A[i]->left = A[i];
                A[i]->right = A[i];
                Fibonacci_min = A[i];
            }
            else
            {
                A[i]->left = Fibonacci_min->left;
                A[i]->right = Fibonacci_min->right;
                (Fibonacci_min->left)->right = A[i];
                Fibonacci_min->left = A[i];

                if(A[i]->key < Fibonacci_min->key)
                    Fibonacci_min = A[i];
            } 
        }
    }  
}

node* fibHeapExtractMin()
{
    node *z = Fibonacci_min;
    find_array.erase(z->vertex);
    node *x;
    node *next;
    if(z!=NULL)
    {
        x = z->child;
        if(x!=NULL)
        {
            do
            {
                next = x->right;
                x->left = Fibonacci_min->left;
                x->right = Fibonacci_min;
                (Fibonacci_min->left)->right = x;
                Fibonacci_min->left = x;
                x->parent = NULL;
                x = next;
            } while (x!=z->child);   
        }
        (z->left)->right = z->right;
        (z->right)->left = z->left;

        if(z==z->right)
            Fibonacci_min = NULL;
        else
        {
            Fibonacci_min = z->right;
            // cout<<".......Consolidating"<<endl;
            consolidate();
        }
        z->child = NULL;
        z->degree = 0;
        z->left = z;
        z->right = z;
        num_nodes--;
    } 
    return z;
}

void fibHeapCut(node *x,node*y)
{
    if(x==x->right)
        y->child = NULL;
    else
    {
        (x->left)->right = x->right;
        (x->right)->left = x->left;
        if(x==y->child)
            y->child = x->right;
    }
    y->degree--;
    x->left = Fibonacci_min->left;
    x->right = Fibonacci_min;
    (Fibonacci_min->left)->right = x;
    Fibonacci_min->left = x;

    x->parent = NULL;
    x->mark = false;
}

void fibHeapCascadingCut(node *y)
{
    node *z = y->parent;
    if(z!=NULL)
    {
        if(y->mark == false)
            y->mark = true;
        else
        {
            fibHeapCut(y,z);
            fibHeapCascadingCut(z);
        }  
    }
}

void fibHeapDecreaseKey(node *x,int val)
{
    x->key = val;
    node *y=x->parent;
    if(y!=NULL && x->key<y->key)
    {
        fibHeapCut(x,y);
        fibHeapCascadingCut(y);
    }
    if(x->key<Fibonacci_min->key)
        Fibonacci_min=x;
}

void dijkstra(vector<pair<int,int>> G[], int V, int src)
{
    // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    fibHeapCreate(V,src);

    while(num_nodes>0)
    {
        node *z = fibHeapExtractMin();
        int u= z->vertex;
        int distu= z->key;
        cout<<"Distance of "<<u<<" from source= "<<distu<<endl;
        // pq.pop();

        int adj = G[u].size();
        for(int i=0;i<adj;i++)
        {
            int v= G[u][i].first;
            int weight = G[u][i].second;
            node *x =fibHeapFind(v);

            if(x!=NULL)
            {
                if(x->key>distu+weight)
                    fibHeapDecreaseKey(x,distu+weight);
            }
        }
    }
}

int main()
{
    int V,E;
    // cout<<"Number of vertices "<<endl;
    cin>>V;
    // cout<<"Number of edges "<<endl;
    cin>>E;
    vector<pair<int,int>> graph[V];
    int src,dest,weight;

    for(int i=0;i<E;i++)
    {
        cin>>src>>dest>>weight;
        graph[src].push_back(make_pair(dest,weight));
        graph[dest].push_back(make_pair(src,weight));
    }
    cin>>src;
    dijkstra(graph,V,src);

    return 0;
}
/*
6 9
0 1 3
0 2 4
0 3 2
1 2 4
1 4 2
2 4 6
3 4 1
3 5 4
4 5 2
0
*/

/*
7 13
0 1 1
0 2 3
0 5 10
1 2 1
1 3 7
1 4 5
1 6 2
2 3 9
2 4 3
3 4 2
3 5 1
3 6 12
4 5 2
0
*/