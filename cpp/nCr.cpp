// All results are calculated mod 1e9+7
// 1<=r<=n<=1e6
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mod=1e9+7;
const int N= 1e6+10;
ll fact[N];

ll power(ll a, ll n){
    ll res=1;
    while(n){
        if(n%2==1){
            res=(res*a)%mod;
            n--;
        }
        else{
            a=(a*a)%mod;
            n/=2;
        }
    }
    return res;
}
int main(){
    int n,r,i;
    
    fact[0]=1;
    for(i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    cin>>n>>r;
    ll num,denom,res,inv_denom;
    num=fact[n];
    denom=(fact[r]*fact[n-r])%mod;
    inv_denom=power(denom,mod-2);
    res=(num*inv_denom)%mod;

    cout<<res<<endl;

   
}