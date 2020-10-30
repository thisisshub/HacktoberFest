// Depth First Search Traversal
#include<stdio.h>
void dfs(int);
void bfs(int);
int G[10][10],visited[10]={0};
int n,f=0,r=-1,q[10]={0};
void main()
{
    int i,j;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    printf("\nDFS Traversal\n");
    dfs(0);
    printf("\n");
    printf("\nBFS Traversal\n");
    bfs(0);
    //printf("\nThe node which are reachable are:\n");
    for(i=0;i<n;i++)
    {
        if(visited[i]==1)
            printf("%d\t",i);
        else
        {
            printf("BFS not possible.");
            break;
        }
    }
}
void dfs(int i)
{
    int j;
    printf("%d\t",i);
    visited[i]=1;
    for(j=0;j<n;j++)
    {
        if(visited[j]==0 && G[i][j]==1)
        {
            dfs(j);
        }
    }
}
void bfs(int v)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(G[v][j]==1 && visited[j]==0)
        {
            q[++r]= j;
        }
        if(f<=r)
        {
            visited[q[f]]=1;
            bfs(q[f++]);
        }
    }
}
