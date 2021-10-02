// { Driver Code Starts
#include <iostream>
using namespace std;

int factorial(int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << factorial(N) << endl;
    }
    return 0;
} // } Driver Code Ends

//User function Template for C++

//Back-end complete function Template for C++

int factorial(int N)
{
    //Your code here
    if (N <= 1)
        return 1;
    return N * factorial(N - 1);
}
