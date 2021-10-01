#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll mx=0,curr=0;
    for(int i=0;i<n;i++){
        curr+=a[i];
        mx=max(mx,curr);
        curr=max(curr,(ll)0);
    }

    cout<<mx<<endl;

}