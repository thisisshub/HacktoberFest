#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main() {
int n ;
cout<<"Enter : ";
cin>>n;
int arr[n];
for(int i =0 ; i<n;i++){
    int t ;
    cin>>t;
    arr[i]=t;
}
cout<<"Enter the Kth position : ";
int k ;
cin>>k;
priority_queue<int>pq;
for(int i = 0; i<k;i++){
    pq.push(-arr[i]);
}
for(int i = k ; i<n;i++){
    if(-pq.top()<arr[i]){
        pq.pop();
        pq.push(-arr[i]);
    }
}
cout<<-pq.top();
return 0;
}