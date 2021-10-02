#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{

    if (n < 10)
    {
        return n;
    }

    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << sumOfDigits(123);
    return 0;
}