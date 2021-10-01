#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main() {
int n ;
cout<<"Enter : ";
cin>>n;
priority_queue<int>pq;
for(int i = 0; i<n;i++){
    int t ;
    cin>>t;
    pq.push(-t);
}
for(int i = 0 ; i<n;i++){
    cout<<(-pq.top())<<" ";
    pq.pop();
}
return 0;
}