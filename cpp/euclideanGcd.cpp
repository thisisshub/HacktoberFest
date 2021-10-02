
#include<iostream>
using namespace std;
int main()
{
	int number, i, a[100], j, temp;
	cout<<"Enter total number of elements :";
	cin>>number;
	cout<<"Enter "<<number<<" numbers :";
	for(i=0; i<number; i++)
	{
		cin>>a[i];
	}
	cout<<"Sorting array using bubble sort technique...\n";
	for(i=0; i<(number-1); i++)
	{
		for(j=0; j<(number-i-1); j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"Elements sorted successfully..!!\n";
	cout<<"Sorted list in ascending order :\n";
	for(i=0; i<number; i++)
	{
		cout<<a[i]<<" ";
	}
}