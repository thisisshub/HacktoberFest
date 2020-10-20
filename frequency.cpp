#include<iostream>
using namespace std;

int main()
{
	int testcase;
	cin>>testcase;
	int i=0;
	while(i!=testcase)
	{
		int size;
		cin>>size;
		int arr[size],j;

		for(j=0;j<size;j++)
		{
			cin>>arr[j];
		}

		int number=0, k;

		for(k=1;k<=size;k++)
		{
			for(j=0;j<size;j++)
			{
				if(k==arr[j])
				{
					number++;
				}
			}

			cout<<number<<" ";
			number=0;
		}

		i++;

	}

	return 0;
}

		
