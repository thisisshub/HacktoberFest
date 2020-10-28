#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int>& a,const pair<int,int>& b){
    return a.second<b.second;//sorting according to finishing time
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	int n,c=1,j=0;vector<pair<int,int>> v;
	cin>>n;
	int s[n],f[n];
	for(int i=0;i<n;i++)
	 cin>>s[i];
	for(int i=0;i<n;i++)
     cin>>f[i];
    for(int i=0;i<n;i++)
     v.push_back(make_pair(s[i],f[i]));
	
	sort(v.begin(),v.end(),comp);
	for(int i=1;i<n;i++)
	{
	 if(v[j].second<=v[i].first)
	    { c++;j=i;}
	}
	cout<<c<<endl;
	}
	return 0;
}
