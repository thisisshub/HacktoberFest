#include <bits/stdc++.h>
using namespace std;

int factorial(int N)
{
    if (N == 0)
    {
        return 1;
    }
    return N * factorial(N - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << factorial(5);
    return 0;
}