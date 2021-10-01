#include<bits/stdc++.h>
using namespace std;

int missing(int arr[],
					int first, int last)
{
	if (first > last)
		return last + 1;

	if (first != arr[first])
		return first;

	int mid = (first+ last) / 2;

	if (arr[mid] == mid)
		return missing(arr,
							mid+1, last);

	return missing(arr, first, mid);
}
int main()
{
	int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
	int n = sizeof(arr2)/sizeof(arr2[0]);
	cout << "Smallest missing no is " <<
		missing(arr2, 0, n-1) << endl;
}

