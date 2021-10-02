// Minimum removals required such that sum of remaining array modulo M is X
// Given an array arr[] consisting of N positive integers and the integers X and M, where 0 <= X < M, the task is to find the minimum number of elements required to be removed such that sum of the remaining array modulo M is equal to X.

// DP solution

// If S % M > X, then the minimum number of elements having sum S % M – X must be removed from the array to make the sum modulo M equal to X.
// Otherwise, the minimum number of elements having sum S % M + M – X must be removed to make the sum modulo M equal to X.
// Follow the steps below to solve the problem: 

// Initialize a dp[] table, table[N + 1][X + 1] where table[i][j] represents the minimum number of elements to remove having indices in the range [0, i] such that their sum is j where X is the sum so be removed.
// Initialize dp[0][i] for each i in the range [1, X] with some large value.
// The dp transitions are as follows:

// dp[i][j] = min(dp[i-1][j], dp[i][j-arr[i-1]]+1) 
// where, i is in the range [1, N] and j is in the range [1, X].
// Print dp[N][X] as the minimum elements to be removed.

// C++ program for the above approach

// Time Complexity: O(N*X) where N is the length of the given array and X is the given integer.
// Auxiliary Space: O(N*X) 

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum
// elements having sum x
int findSum(vector<int> S, int n, int x)
{

	// Initialize dp table
	vector<vector<int> > table(n + 1,
							vector<int>(
								x + 1, 0));

	for (int i = 1; i <= x; i++) {
		table[0][i] = INT_MAX - 1;
	}

	// Pre-compute subproblems
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= x; j++) {

			// If mod is smaller than element
			if (S[i - 1] > j) {
				table[i][j] = table[i - 1][j];
			}
			else {

				// Minimum elements with sum
				// j upto index i
				table[i][j]
					= min(table[i - 1][j],
						table[i][j
								- S[i - 1]]
							+ 1);
			}
		}
	}

	// Return answer
	return (table[n][x] > n)
			? -1
			: table[n][x];
}

// Function to find minimum number
// of removals to make sum % M in
// remaining array is equal to X
void minRemovals(vector<int> arr,
				int n, int m, int x)
{

	// Sum of all elements
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	// Sum to be removed
	int requied_Sum = 0;

	if (sum % m < x)
		requied_Sum
			= m + sum % m - x;
	else
		requied_Sum
			= sum % m - x;

	// Print answer
	cout << findSum(arr, n,
					requied_Sum);
}

// Driver Code
int main()
{

	// Given array
	vector<int> arr = { 3, 2, 1, 2 };

	// Given size
	int n = arr.size();

	// Given mod and x
	int m = 4, x = 2;

	// Function call
	minRemovals(arr, n, m, x % m);

	return 0;
}
