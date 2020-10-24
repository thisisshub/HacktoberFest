#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define endl "\n"

int n, e;
vector<int> adj[100];
bool visited[100], color[100];

void dfs(int z) {
	visited[z] = true;
	for ( auto j : adj[z] ) {
		if ( !visited[j] ) {
			color[j] = !color[z];
			dfs(j);
		}
	}
}

int main() {

	int a, b;
	cin >> n >> e;
	fo(i, n) visited[i] = color[i] = false;
	fo(i, e) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fo(i, n) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	fo(i, n) visited[i] = false;

	fo(i, n) {
		for ( auto j : adj[i]) {
			if (color[i] == color[j]) {
				cout << "Not Bipatite!";
				return 0;
			}
		}
	}
	cout << "Bipatite!";
	return 0;
}