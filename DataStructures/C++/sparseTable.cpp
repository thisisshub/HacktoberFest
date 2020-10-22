#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int main() {

	int n, m;
	cin >> n >> m;

	int log[n], arr[n];
	Fo(i, 2, n) log[i] = log[i / 2] + 1;
	fo(i, n) cin >> arr[i];
	int k = log[sizeof(log) / sizeof(log[0]) - 1] + 1;

	int sparse[k][n];
	fo(i, n) sparse[0][i] = arr[i];

	Fo(i, 1, k) for (int j = 0; j + (1 << i) <= n; j++) {
		sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
	}

	while (m--) {
		int a, b, l;
		cin >> a >> b;
		l = log[b - a];
		a = min(sparse[l][a], sparse[l][b - (1 << l)]);
		cout << a << endl;
	}

	// fo(i, k) {
	// 	fo(j, n) cout << sparse[i][j] << " ";
	// 	cout << endl;
	// }

	return 0;
}