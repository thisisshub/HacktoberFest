/*
Input:
2
5
act cat tac god dog
3
act cat tac
Output:
2 3
3
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		map<string,int> m;
		vector<int> v;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++){
			cin>>s[i];
		//	cin.ignore();
			sort(s[i].begin(),s[i].end());
			m[s[i]]++;
		}
		map<string,int>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			v.push_back(it->second);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
		    cout<<v[i]<<" ";
		}
		cout<<endl;
	}
}

