//palindrome check

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,f=1;
	    cin>>n;
	    string s;
	    cin>>s;
	    int l=0,r=n-1;
	    while(r>l){
	        if(s[l]==s[r])
	        {
	            l++;
	            r--;
	        }
	        else
	        {f=0;break;}
	    }
	    if(f)
	    cout<<"Yes"<<endl;
	    else
	    cout<<"No"<<endl;
	}
	return 0;
}
