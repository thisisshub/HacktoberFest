#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int n, e, weight[100];
vector<pair<int, pair<int, int>>> adj;

int main() {

	int a, b, w;
	cin >> n >> e;
	fo(i, e) {
		cin >> a >> b >> w;
		adj.push_back({ w, { a, b } });
	}

	fo(i, n) weight[i] = INT_MAX;
	weight[0] = 0;

	fo(i, n - 1) {
		fo(j, e) {
			a = adj[j].second.first;
			b = adj[j].second.second;
			w = adj[j].first;
			if (weight[a] != INT_MAX && weight[a] + w < weight[b]) weight[b] = weight[a] + w;
		}
	}

	fo(i, n) cout << i << " : " << weight[i] << endl;

	// fo(i, e)
	// cout << "edge no. " << i << " : " << adj[i].second.first << " -> " << adj[i].second.second  << ", weight : " << adj[i].first << endl;

	return 0;
}