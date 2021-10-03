#include <bits/stdc++.h>
using namespace std;

void MinMax(int arr[],int size)
{
    int min=0,max = 0;
    if(size == 1)
    {
        min=max=arr[0];
    }
    if(arr[0]>arr[1])
    {
        min = arr[1];
        max = arr[0];
    }
    else
    {
        min = arr[0];
        max = arr[1];
    }
    for(int i=2;i<size;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        else if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    cout<<"Maximun number is: "<<max<<endl;
    cout<<"Minimum number is: "<<min<<endl;
}
int main()
{
    int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    MinMax(arr,size);
    return 0;
}
