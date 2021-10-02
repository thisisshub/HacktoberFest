#include <bits/stdc++.h>
using namespace std;

void printNto1(int N)
{
    if (N == 0)
    {
        return;
    }
    printNto1(N - 1);
    cout << N << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    printNto1(10);

    return 0;
}