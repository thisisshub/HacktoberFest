#include <bits/stdc++.h>
using namespace std;


void PrintArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}

void KthMax(int arr[],int size,int kth){
    if(kth <= size){
        cout<<"The "<<kth<<" Element Of Arr is: "<<arr[kth-1]<<endl;
    }else{
        cout<<"Out of limit"<<endl;
    }
}
int main(){
    int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int kth;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter Kth Value To Find: "<<endl;
    cin>>kth;
    PrintArr(arr,size);
    sort(arr,arr+size);
    KthMax(arr,size,kth);
    PrintArr(arr,size);
    return 0;
}