#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

struct edge {
	int u;
	int v;
	int w;
};

int e, n;
int parent[100];
edge adj[100];

bool compare(edge u, edge v) {
	return u.w <= v.w;
}

int find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}

void pairIt(int a, int b) {
	parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0, a, b;
	cin >> n >> e;
	fo(i, e) cin >> adj[i].u >> adj[i].v >> adj[i].w;
	fo(i, n + 1) parent[i] = -1;

	sort(adj, adj + e, compare);

	fo(i, e) {
		a = find(adj[i].u);
		b = find(adj[i].v);
		if (a != b) {
			pairIt(a, b);
			sum += adj[i].w;
		}
	}

	fo(i, e) cout << adj[i].u << " -> " << adj[i].v << " = " << adj[i].w << endl;

	cout << "MST weight -> " << sum;

	return 0;
}