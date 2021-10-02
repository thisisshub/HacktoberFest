#include <bits/stdc++.h>
using namespace std;

void printNto1tailrecursion(int N,int i)
{
    if (N == 0)
    {
        return;
    }
    cout << i << " ";

    printNto1tailrecursion(N - 1,i+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    printNto1tailrecursion(10,1);

    return 0;
}