#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,num=0;
	char s[40];
	cin>>s;
	n=strlen(s);
	for(int i=0,c=n-1;i<n;i++,c--)
	{
		if(s[i]=='1')
		{
			num+=pow(2,c);
		}
	}
	cout<<num<<endl;
	}
	return 0;
}


