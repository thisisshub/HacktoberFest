// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6


#include <bits/stdc++.h>
#include "IpOp.h"
using namespace std;


void PrintArr(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}
void CheckNegativeOrNot(int arr[],int size)
{
    int j = 0;
    for (int i=0;i<size;i++)
    {
        if (arr[i] < 0) {
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

int main()
{
    FileReadWrite();
    int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the element of array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"value's of array before negative check"<<endl;
    PrintArr(arr,size);
    cout<<"value's of array after negative check"<<endl;
    CheckNegativeOrNot(arr,size);
    PrintArr(arr,size);
    return 0;
}