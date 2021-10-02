// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends

//User function Template for C++

//Complete this function
int countDigits(int n)
{
    //Your code here
    if (n < 10)
        return 1;
    return 1 + countDigits(n / 10);
}

// { Driver Code Starts.

int main()
{
    int T;

    //taking testcases
    cin >> T;
    while (T--)
    {
        int n;

        //taking number n
        cin >> n;

        //calling countDigits
        cout << countDigits(n) << endl;
    }
    return 0;
}

// } Driver Code Ends