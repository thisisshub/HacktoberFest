#include<bits/stdc++.h>
#include "IpOp.h"

using namespace std;

void Rotation(int arr[], int size)
{
    int temp = arr[0];
    for(int i=0; i<size ; i++)
    {
        if(i == size-1)
        {
            arr[i] = temp;
        }
        else
        {
            arr[i] = arr[i+1];
        }
        
    }
}

void PrintArr(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}

int main()
{
    FileReadWrite();
    int arr[10];
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    PrintArr(arr,10);
    Rotation(arr,10);
    PrintArr(arr,10);
}