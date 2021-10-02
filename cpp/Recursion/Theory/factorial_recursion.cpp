#include <bits/stdc++.h>
using namespace std;

int factorial(int n, int k)
{
    if (n == 0)
    {
        return k;
    }
    return factorial(n - 1, k * n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << factorial(5, 1);
    return 0;
}