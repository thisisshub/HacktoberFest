//This question is to print the second largest element's index number from the given array
//input:-5 4 3 2 1
//output :-1 becoz 4 is the second largest element and it's index value is 1

#include<bits/stdc++.h>
using namespace std;
int secondlargest(int arr[],int n)
{
    int res =-1,largest =0;
    for(int i=0;i<n;i++)
    {
       if(arr[i]>arr[largest])
       {
           res = largest;
           largest=i;
       }
       else if(arr[i]!=arr[largest])
       {
           if(res==-1||arr[i]>arr[res])
           res =i;
       }
    }
return res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<secondlargest(arr,n);
return 0;

}

