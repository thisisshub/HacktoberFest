#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[5][5];//creates a 2-D Array
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		 cin>>arr[i][j];
		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<arr[i][j];
		}
	}
return 0;
}
