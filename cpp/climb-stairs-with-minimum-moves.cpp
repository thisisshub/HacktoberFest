#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int dp[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = 0;
        int b = INT_MAX;
        for (int j = 1; j <= a[i] && i + j <= n; j++)
        {
            b = min(b , dp[i+j]);
        }
        if (b != INT_MAX)
        {
            dp[i] += b + 1;
        }
        else dp[i] = INT_MAX;
    }

   
    cout << dp[0] << endl;
}
