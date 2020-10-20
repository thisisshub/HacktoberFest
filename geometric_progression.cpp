#include<iostream>
using namespace std;

int main()
{
	int testcase;
	cin>>testcase;
	int i=0;
	while(i!=testcase)
	{
		int a,b;
		cin>>a;
		cin>>b;
		int n,m;

		cin>>n;
		m=n-1;
		float r,ans;
		r=b/a;
		ans=a*(pow(r,m));
		cout<<ans<<endl;

		i++
	}
	return 0;
}

