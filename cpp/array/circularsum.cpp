#include<bits/stdc++.h>
using namespace std;

int normalsum(int arr[], int n)
{
 int res = arr[0];
 int maxend = arr[0];
 
 for(int i=1 ; i<n ; i++)
 {
   maxend = max(maxend+arr[i],arr[i]);
   res = max(res , maxend);
 }
return res;
} 

int circularsum(int arr[], int n)
{
 int normal = normalsum(arr,n);
    
    if(normal<0)
       return normal;

    int arr_sum=0;
    for(int i=0;i<n;i++)
    {
        arr_sum +=arr[i];
        arr[i] = -arr[i];

    }
  int max_circular = arr_sum + normalsum(arr,n);
  return max(normal,max_circular) ;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
      cin>>arr[i];


cout<<circularsum(arr,n);
return 0;
}