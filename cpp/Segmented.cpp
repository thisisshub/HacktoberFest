#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define p pair
#define ld long double
#define rep(start,end,i) for(ll i=start;i<end;i++)
#define repb(start,end,i) for(ll i=start-1;i>=end;i--)
#define mp make_pair
#define popc __builtin_popcount()
#define lb lower_bound
#define ub upper_bound
using namespace std;

ll arr[] = {5 , 2 , 4 , 1 , 4 , 7 , 6 , 4 , 5};
ll size = 9;
ll seg[36];
ll lazy[36];

void build(ll ind,ll high,ll low){
	if(low == high){
		seg[ind] = arr[low];
		return;
	}
	int mid = (low+high)>>1;
	build(2*ind+1,mid,low);
	build(2*ind+2,high,mid+1);
	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r){
	if(low>=l && high<=r)
		return seg[ind];
	if(high<l || low>r) return 0;
	int mid = (low + high)>>1;
	int left = query(2*ind+1,low,mid,l,r);
	int right = query(2*ind+2,mid+1,high,l,r);
	return left+right;
}

void pointUpdate(int ind,int low,int high,int node,int val){
	if(low == high)
		seg[ind] += val;
	else{
		int mid = (low+high)>>1;
		if(node<=mid && node>=low) pointUpdate(2*ind+1,low,mid,node,val);
		else pointUpdate(2*ind+2,mid+1,high,node,val);
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
}

void rangeUpdate(int ind,int low,int high,int l,int r,int val){
	if(lazy[ind] != 0){
		seg[ind] += (high-low+1)*lazy[ind];
		if(low!=high){
			lazy[2*ind+1] += lazy[ind];
			lazy[2*ind+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if(r<low || l>high || low>high) return;
	if(low>=l && high<=r){
		seg[ind] += (high-low+1)*val;
		if(low != high){
			lazy[2*ind+1] += val;
			lazy[2*ind+2] += val;
		}
		return;
	}
	int mid = (high + low)>>1;
	rangeUpdate(2*ind+1,low,mid,l,r,val);
	rangeUpdate(2*ind+2,mid+1,high,l,r,val);
	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int querySumLazy(int ind,int low,int high,int l,int r){
	if(lazy[ind] != 0){
		seg[ind] += (high-low+1)*lazy[ind];
		if(low!=high){
			lazy[2*ind+1] += lazy[ind];
			lazy[2*ind+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if(r<low || l>high || low>high) return 0;
	if(low>=l && high<=r)
		return seg[ind];
	int mid = (high + low)>>1;
	return querySumLazy(2*ind+1,low,mid,l,r) + querySumLazy(2*ind+2,mid+1,high,l,r);
}

void solve(){
	ll test=1;
	// cin>>test;
	while(test--)
	{
		memset(seg,0,sizeof(seg));
		memset(lazy,0,sizeof(lazy));
		build(0,size,0);
		cout<<query(0,0,size,3,5)<<endl;
		pointUpdate(0,0,size,3,4);
		cout<<querySumLazy(0,0,size,3,5)<<endl;
		rangeUpdate(0,0,size,1,4,5);
		cout<<querySumLazy(0,0,size,3,5)<<endl;
	}
	return;
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
return 0;
}