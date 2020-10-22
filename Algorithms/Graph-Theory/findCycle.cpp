#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int n, e;
bool visited[100], temp[100];
vector<int> adj[100];

bool dfs(int z) {
	visited[z] = true;
	temp[z] = true;
	for ( auto j : adj[z]) {
		if (temp[j])
			return true;
		if (!visited[j])
			if (dfs(j))
				return true;
	}
	temp[z] = false;
	return false;
}

int main() {

	int a, b;
	cin >> n >> e;
	fo(i, n) {
		visited[i] = false;
		temp[i] = false;
	}
	fo(i, e) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	fo(i, n) {
		if (!visited[i])
			if (dfs(i))
				break;
	}

	fo(i, n) {
		if (temp[i])
			cout << i << " -> ";
	}

	return 0;
}