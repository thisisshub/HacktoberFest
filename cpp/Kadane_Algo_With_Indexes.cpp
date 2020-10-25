#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; ++i)

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,i, max_current, max_global, start = 0, end = 0, end_global = 0;
    cin>>n;
    ll a[n];

    REP(i,0,n-1)
        cin>>a[i]; 

    max_current = max_global =  a[0];
    REP(i,1,n-1){
        if(a[i] > a[i] + max_current){
            start = i;
            end = i;
            max_current = a[i];
        }
        else{
            end = i;
            max_current = max_current + a[i];
        }

        if(max_current > max_global){
            max_global = max_current;
            end_global = end;
        }

    }
    cout << "Max Contiguous Sum : " << max_global << endl << "Start Index : " << start << endl << "Last Index : " << end_global;

    
    return 0;
}