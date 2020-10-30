#include <iostream>
using namespace std;
//program to find pascal triangle
void pascal(int n)
{
	for (int i = 1; i < n; i++)
		int c = 1;
	for (int j = 1; j <= i; j++)
		cout << " ";
	c = c * (i - j) / j;
	cout << endl;
}
int main()
{
	pascal(8);
	return 0;
}
