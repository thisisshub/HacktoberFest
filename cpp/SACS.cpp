
// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return minimum
// number of moves required
int getMinimumMoves(int n, int k, int d,
                    vector<int> a)
{
    int MAX = 100000;

    // Stores the number of moves
    // required to obtain respective
    // values from the given array
    vector<int> v[MAX];

    // Traverse the array
    for (int i = 0; i < n; i++) {
        int cnt = 0;

        // Insert 0 into V[a[i]] as
        // it is the initial state
        v[a[i]].push_back(0);

        while (a[i] > 0) {
            a[i] /= d;
            cnt++;

            // Insert the moves required
            // to obtain current a[i]
            v[a[i]].push_back(cnt);
        }
    }

    int ans = INT_MAX;

    // Traverse v[] to obtain
    // minimum count of moves
    for (int i = 0; i < MAX; i++) {

        // Check if there are at least
        // K equal elements for v[i]
        if (v[i].size() >= k) {

            int move = 0;

            sort(v[i].begin(), v[i].end());

            // Add the sum of minimum K moves
            for (int j = 0; j < k; j++) {

                move += v[i][j];
            }

            // Update answer
            ans = min(ans, move);
        }
    }

    // Return the final answer
    return ans;
}

// Driver Code
int main()
{
    int N = 5, K = 3, D = 2;
    vector<int> A = { 1, 2, 3, 4, 5 };

    cout << getMinimumMoves(N, K, D, A);

    return 0;
}
