#include<bits/stdc++.h>
using namespace std;

const int Col_size =20;
const int Row_size =20;

int main()
{
	
	int arr[Col_size][Row_size];//creates a 2-D Array
	for(int i=0;i<Col_size;i++)
	{
		for(int j=0;j<Row_size;j++)
		{
		 cin>>arr[i][i];
		}
		cout<<endl;
	}
	for(int i=0;i<Col_size;i++)
	{
		for(int j=0;j<Row_size;j++)
		{
			cout<<arr[i][i];
		}
		cout<<endl;
	}
	

	return 0;
}
