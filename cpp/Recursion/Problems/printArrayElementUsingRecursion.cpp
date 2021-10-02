// { Driver Code Starts
#include <iostream>
using namespace std;

void printArrayRecursively(int arr[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        printArrayRecursively(arr, N);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

//User function Template for C++

void printArrayRecursively(int arr[], int n)
{
    //Your code here
    //Use recursion to print array elements from start to end

    if (n == 0)
    {
        return;
    }

    printArrayRecursively(arr, n - 1);

    cout << arr[n - 1] << " ";
}
