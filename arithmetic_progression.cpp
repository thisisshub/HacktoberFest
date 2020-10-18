#include<iostream>
using namespace std;

int main()
{
	int testcase, i;
	cin>>testcase;

	i=0;
	while(i!=testcase)
	{
		int num1, num2;
		cin>>num1;
		cin>>num2;

		int nterm;
		cin>>nterm;

		int difference;
		difference=num2-num1;

		int nthterm;
		nthterm=num1+(nterm-1)*difference;
		cout<<nthterm<<endl;

		i++;

	}
	return 0;
}
