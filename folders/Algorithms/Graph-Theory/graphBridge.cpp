#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int n, e, cnt;
vector<int> adj[100];
int in[100], link[100];
bool visited[100];

void dfs(int cur, int parent) {
	in[cur] = link[cur] = cnt++;
	visited[cur] = true;
	for (auto j : adj[cur]) {
		if (j == parent) continue;
		else {
			if (visited[j]) {
				link[cur] = min(in[j], link[cur]);
			} else {
				dfs(j, cur);
				if (link[cur] < link[j]) cout << cur << " -> " << j << " is a bridge" << endl;
				link[cur] = min(link[cur], link[j]);
			}
		}
	}
}

int main() {

	cin >> n >> e;
	int a, b;
	fo(i, e) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	fo(i, n)
	for (auto j : adj[i]) cout << i << " -> " << j << endl;

	dfs(0, -1);

	return 0;
}