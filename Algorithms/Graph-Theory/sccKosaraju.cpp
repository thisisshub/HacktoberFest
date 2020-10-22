#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int n, e;
vector<int> adj[50], rev[50];
bool visited[50];
stack<int> s;

void dfs(int z) {
	visited[z] = true;
	for (auto j : adj[z])
		if (!visited[j])
			dfs(j);
	s.push(z);
}

void ndfs(int z) {
	visited[z] = true;
	cout << z << " ";
	s.pop();
	for (auto j : rev[z])
		if (!visited[j])
			ndfs(j);
}

int main() {

	int a, b;
	cin >> n >> e;
	fo(i, e) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	fo(i, n) visited[i] = false;

	fo(i, n)
	if (!visited[i])
		dfs(i);

	fo(i, n)
	for (auto j : adj[i])
		rev[j].push_back(i);

	// fo(i, n)
	// for (auto j : adj[i])
	// 	cout << i << "->" << j << endl;

	// fo(i, n)
	// for (auto j : rev[i])
	// 	cout << i << "->" << j << endl;

	fo(i, n) visited[i] = false;

	while (!s.empty()) {
		a = s.top();
		if (!visited[a]) {
			ndfs(a);
			cout << endl;
		}
		else s.pop();
	}

	return 0;
}