// Dijkstras-shortest-path-algorithm
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int ver, edg;
	cin>>ver>>edg;
	vector< pair<int,int> > adj_m[ver];

	for(int i=0;i<edg;i++){
		int source, destination, val;
		cin>>source>>destination>>val;
		adj_m[source].push_back({destination,val});
	}

	int source;
	cin>>source;

	vector<bool> sp;
	vector<int>distance;

	for(int i=0;i<ver;i++){
		distance.push_back(INT_MAX);
	}

	distance[source]=0;
	for(int i=0;i<ver;i++){
		sp.push_back(false);
	}

	for(int count=0;count<(ver-1);count++){
		vector<int>:: iterator it = min_element(distance.begin(),distance.end());
		int index = it - distance.begin();
		sp[index] = true;
		for(int i = 0;i<adj_m[index].size();i++)
		{
			int ver = (adj_m[index][i]).first;
			int w = (adj_m[index][i]).second;
			if((sp[ver]==false) && distance[ver]>distance[index]+w)
			{
				distance[ver] = distance[index] + w;
			}
		}
	}

	for(int i=0;i<ver;i++)cout<<distance[i]<<' ';
		cout<<endl;
}
