// { Driver Code Starts
#include <iostream>
using namespace std;

int recursiveSum(int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << recursiveSum(N) << endl;
    }
    return 0;
} // } Driver Code Ends

//User function Template for C++

int recursiveSum(int N)
{
    //Your code here
    //Recursively sum from 1 to N and return

    if (N == 0)
        return 0;
    return N + recursiveSum(N - 1);
}