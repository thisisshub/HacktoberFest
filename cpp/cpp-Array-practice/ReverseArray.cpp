#include <bits/stdc++.h>
using namespace std;
 /*
 function to reverse the array
 */
void RvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}    
/*
 function to print the array
*/
void PrintArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
 
   cout << endl;
}
 
int main()
{
    int arr[10];
     
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    PrintArray(arr, n);
     
    RvereseArray(arr, 0, n-1);
     
    cout << "Reversed array is" << endl;
     
    PrintArray(arr, n);
     
    return 0;
}