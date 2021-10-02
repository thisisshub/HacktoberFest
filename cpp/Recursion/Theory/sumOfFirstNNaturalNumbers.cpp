#include <bits/stdc++.h>
using namespace std;

int sumNNaturalNumbers(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + sumNNaturalNumbers(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << sumNNaturalNumbers(5);
    return 0;
}