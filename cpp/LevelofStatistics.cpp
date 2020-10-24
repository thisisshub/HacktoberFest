#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int t,n;
	cin>>t;
	while(t--)
	 {
		cin>>n;
		int x,y,p=0,q=0;
		bool a=true;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			if(x<p || y<q || y-q>x-p)
			{
			   	a=false;
			}
			p=x;
			q=y;
		}
		if(a)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}