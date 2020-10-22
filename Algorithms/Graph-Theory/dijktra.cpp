#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int n, e;
set<pair<int, int>> st;
vector<int> weight(100, INT_MAX);
vector<pair<int, int>> adj[100];

int main() {

	cin >> n >> e;
	int a, b, w;
	fo(i, n) {
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}

	weight[0] = 0;
	st.insert(make_pair(0, 0));

	while (!st.empty()) {
		pair<int, int> temp = *(st.begin());
		st.erase(st.begin());
		a = temp.second;
		for (auto j : adj[a]) {
			w = j.second;
			b = j.first;
			if (weight[b] > weight[a] + w) {
				if (weight[b] != INT_MAX) st.erase(st.find(make_pair(weight[b], b)));
				weight[b] = weight[a] + w;
				st.insert(make_pair(weight[b], b));
			}
		}
	}

	fo(i, n) cout << i << " : " << weight[i] << endl;

	return 0;
}

