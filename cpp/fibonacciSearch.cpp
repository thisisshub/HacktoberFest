#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
int fibonacciSearch(int arr[],int n,int x);
int main()
{
    int arr[10],offset=-1,i,x,n=10;
    void clrscr(void);
    cout<<"Enter 10 values inside the array: ";
    for(i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter value to be searched:";
    cin>>x;
    int found=fibonacciSearch(arr,n,x);
    getch();
}
int fibonacciSearch(int arr[],int n,int x)
{
    int fibm,fibm1=1,fibm2=0,offset=-1,i;
    fibm=fibm1+fibm2;
    while(fibm<n)
    {
        fibm2=fibm1;
        fibm1=fibm;
        fibm=fibm1+fibm2;
    }
    while(fibm>1)
    {
        i=min(offset+fibm2,n-1);
        if(arr[i]<x)
        {
            fibm=fibm1;
            fibm1=fibm2;
            fibm2=fibm-fibm1;
            offset=i;
        }
        else if(arr[i]>x)
        {
            fibm=fibm2;
            fibm1=fibm1-fibm;
            fibm2=fibm-fibm1;
        }
        else
        {
            cout<<"Value found at index: "<<i<<"\n";
            break;
        }
    }
    if(fibm1&&arr[offset+1]==x)
    {
        cout<<"Value found at: "<<i+1;
    }
    else
    {
        cout<<"Value not found!";
    }
    getch();
}