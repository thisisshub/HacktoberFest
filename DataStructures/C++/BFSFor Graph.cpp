#include <bits/stdc++.h>
using namespace std;
#define fr(i, a, b) for (long long i = a; i < b; ++i)
#define fr2(i, b, a) for (long long i = b; i >= a; --i)
#define pb push_back
#define eb emplace_back
#define set0(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))
#define setinf(a) memset(a, 126, sizeof(a))
#define trace(a) cerr << #a << ": " << a << endl
#define N 1000000007
#define PI acos(-1.0)
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vllp;
typedef pair<long long, long long> llp;
typedef long long int ll;
typedef unsigned long long ull;
ll parent[1000],depth[10000],used[10000];
vector<ll> gp[1000];
ll n;
void bfs(int root){
	queue<ll> q;
	q.push(root);
	depth[root]=0;
	parent[root]=-1;
	while(!q.empty()){
		ll curr=q.front();
		q.pop();
		for(ll x:gp[curr]){
			if(used[x]==0){
				used[x]=1;
				q.push(x);
				depth[x]=depth[curr]+1;
				parent[x]=curr;
			}
		}
	}
}
int main()
{
    cout<<"enter vertexes";
    cin>>n;
    cout<<"enter edges count\t:";
    ll edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
		ll u,v;
		cin>>u>>v;
		gp[u].pb(v);
	}
	bfs(0);
	fr(i,0,n){
		cout<<i<<"->"<<depth[i]<<"\n";
	}
}
