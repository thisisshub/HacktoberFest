#include <bits/stdc++.h>
using namespace std;

int findEqualHalves(int arr[], int size)
{
    int right_sum = 0, left_sum = 0;
    for (int i = 1; i < size; i++)
        right_sum += arr[i];
    for (int i = 0, j = 1; j < size; i++, j++) {
        right_sum -= arr[j];
        left_sum += arr[i];
        if (left_sum == right_sum)
            return arr[i + 1];
    }

    return -1;
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
        cin>>arr[i];
    cout <<findEqualHalves(arr, size);
    return 0;
}
