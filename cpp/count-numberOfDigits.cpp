#include <iostream>
using namespace std;
int findNumberDigits(int n)
{
    static int count = 1;
    if (n / 10 == 0)
        return count;
    count++;
    int res = findNumberDigits(n / 10);
    return res;
}
int main()
{
    int n;
    cout<<"Enter the number n"<<endl;
    cin >> n;
    cout << findNumberDigits(n);
}