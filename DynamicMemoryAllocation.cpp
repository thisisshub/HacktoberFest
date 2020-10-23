#include<iostream>
using namespace std;
int
main ()
{
  int *p, *n, i, sum = 0;

  n = new int;

  if (n == NULL)
    {
      cout << "Memory allocation failed!";
    }
  else
    {
      cout << "Enter the number of elements:";
      cin >> *n;
    }
  p = new int (*n);
  if (p == NULL)
    {
      cout << "Memory allocation failed";
    }
  else
    {
      cout << "\nEnter the elements:\n";
      for (i = 0; i < *n; i++)
	{
	  cin >> p[i];
	  sum = sum + p[i];

	}
      cout << "Sum:" << endl << sum;
    }
  delete n;
  delete[]p;

}
