#include<bits/stdc++.h>
using namespace::std;
#define MAX 1000000000
int main()
{
	vector<bool> v(MAX,true);
	for(int i=2;i*i<=MAX;i++)
	{
		if(v[i])
		{
			for(int j=i*i;j<=MAX;j=j+i)
				v[j]=false;
		}
	}
	int t;
	cout<<"Enter number of test cases ";
	cin>>t;
	while(t--)
	{
		int min,max;
		cout<<"Enter minimum and maximum between which too find prime numbers ";
		cin>>min>>max;
		
		for(int i=min;i<=max;i++)
			if(v[i])
				cout<<i<<endl;
	}
}
