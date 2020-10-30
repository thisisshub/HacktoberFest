#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

// one index fenwick tree / binary indexed tree

int LSB(int a) {
	return pow(2, ffs(a) - 1);
}

void generate_fenwick_table(int *arr, int& n) {
	fo(i, n) {
		int temp = i + 1 + LSB(i + 1);
		if (temp <= n) arr[temp] += arr[i + 1];
	}
}

int get_sum(int *arr, int a) {
	if (a < 1) return 0;
	int ans = 0;
	while (a) {
		ans += arr[a];
		a -= LSB(a);
	}
	return ans;
}

void update(int i, int v, int &n, int *arr) {
	while (i <= n) {
		arr[i] += v;
		i += LSB(i);
	}
}

int findIndex(int k, int &n, int *arr) {
	int sum = 0, curr = 0;
	for (int i = log2(n); i >= 0; i--) {
		if (sum + arr[curr + (1 << i)] < k) {
			curr += 1 << i;
			sum += arr[curr];
		}
	}
	return curr;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int n, q, a, b;
	cin >> n;

	// fenwick tree construction
	int arr[n + 1];
	fo(i, n) cin >> arr[i + 1];
	generate_fenwick_table(arr, n);

	fo(i, n) cout << arr[i + 1] << " ";
	cout << endl;

	// range queries
	cin >> q;
	fo(i, q) {
		cin >> a >> b;
		cout << get_sum(arr, b) - get_sum(arr, a - 1) << endl;
	}

	// point updates
	cin >> q;
	fo(i, q) {
		// index and value
		cin >> a >> b;
		update(a, b, n, arr);
	}


	fo(i, n) cout << arr[i + 1] << " ";
	cout << endl;

	// binary lifting
	cout << findIndex(10, n, arr);

	return 0;
}