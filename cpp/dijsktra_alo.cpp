#include<stdio.h>
#include<iostream>
using namespace std;
#define INFINITY 9999
#define limit 20

void dijkstra(int graph[limit][limit], int n, int first)
{
	int cost[limit][limit], dist[limit], pred[limit];
	int visited[limit], count, minimum, next, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(graph[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=graph[i][j];

	for(i=0;i< n;i++)
	{
		dist[i]=cost[first][i];
		pred[i]=first;
		visited[i]=0;
	}
	dist[first]=0;
	visited[first]=1;
	count=1;
	while(count < n-1){
		minimum=INFINITY;
		for(i=0;i < n;i++)
			if(dist[i] < minimum&&!visited[i])
			{
				minimum=dist[i];
				next=i;
			}
		visited[next]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(minimum+cost[next][i] < dist[i])
				{
					dist[i]=minimum+cost[next][i];
					pred[i]=next;
				}
			count++;
	}

	for(i=0;i < n;i++)
		if(i!=first)
		{
			cout<<endl<<"Distance of "<< i<<" = "<< dist[i];
			cout<<endl<<"Path = "<< i;
			j=i;
			do
			{
				j=pred[j];
				cout<<" <-"<< j;
			}
			while(j!=first);
		}
}


int main(){
	int graph[limit][limit], i, j, n, u;
	cout<<endl<<"Enter the no. of vertices of the graph: ";
	cin>>n;
	cout<<endl<<"Enter the adjacency matrix corresponding to the graph :"<<endl;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			cin>>graph[i][j];
	cout<<endl<<"Enter the starting vertex : ( 0-"<<n-1<<" )"<<endl;
	cin>>u;
	cout<<endl<<"Dijkstra’s algorithm for the above graph is:  "<<endl;
	dijkstra(graph,n,u);
}


