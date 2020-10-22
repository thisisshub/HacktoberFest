#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll a, ll b, ll mod){
  ll res = 1; 
  while(b > 0){
        if(b%2) res = ((res%mod)*(a%mod))%mod;
        b = b/2;
        a = ((a%mod)*(a%mod))%mod;
  }
  return res;
}

int main(){
    ll a = 5;
    ll b = 2;
    ll ans = power(5,2,100000007);
    if(ans==25) return 0;
    else return 1;
}
