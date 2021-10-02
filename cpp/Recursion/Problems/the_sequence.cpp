// { Driver Code Starts
#include <iostream>
using namespace std;

int theSequence(int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << theSequence(N) << endl;
    }
    return 0;
} // } Driver Code Ends

//User function Template for C++

int theSequence(int n)
{
    //Your code here

    if (n == 0)
    {
        return 1;
    }

    return n + n * theSequence(n - 1);
}