#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int arr[], int size)
{
    int low = 0, high = size - 1, mid = 0;

    while (mid <= high)
    {

        if (arr[mid] == 0)
            swap(&arr[mid++], &arr[low++]);

        else if (arr[mid] == 1)
            mid++;

        else
            swap(&arr[mid], &arr[high--]);
    }
}
void PrintArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}
int main()
{
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    PrintArr(arr,size);
    sort012(arr, size);
    PrintArr(arr,size);    
}