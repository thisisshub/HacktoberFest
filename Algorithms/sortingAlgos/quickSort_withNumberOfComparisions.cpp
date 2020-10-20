#include<iostream>
using namespace std;

void quickSort(int[], int, int);
int getPivot(int[], int, int);
int partition(int[], int, int, int);
unsigned long long comparisions=0;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr[i]=temp;
	}
	quickSort(arr,0,n-1);
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Number of comparisions to sort "<<comparisions;
}

void quickSort(int arr[], int l, int h)
{
	if(l>=h)
	    return;
	int pivot=getPivot(arr, l, h);
	int m=partition(arr, l, h, pivot);
	quickSort(arr, l, m-1);
	quickSort(arr, m+1, h);
	return;
}

int partition(int arr[], int l, int h, int pivot)
{
	comparisions+=(h-l);
	if(l>=h)
	    return l;
	int i=l+1, j=l+1, n=h-l, ele;
	int temp;
	temp=arr[l];
	arr[l]=arr[pivot];
	arr[pivot]=temp;
	ele=arr[l];
	for(j=l+1;j<=h;j++)
	    if(ele>arr[j])
	    {
	    	temp=arr[i];
	    	arr[i]=arr[j];
	    	arr[j]=temp;
	    	i++;
		}
	arr[l]=arr[i-1];
	arr[i-1]=ele;
	return i-1;
}

int getPivot(int arr[], int l, int h)
{
	//in case of pivot element is first element
	return l;
	//in case of pivot element is last element
	//return h;
	//in case of median of 3
	int m=l+((h-l)/2);
	int low=arr[l], high=arr[h], mid=arr[m];
	if( low>mid && low<high )
	    return l;
	if( low<high && high<mid)
	    return h;
	if( mid>high && mid<low)
	    return m;
	if( low<mid && low>high )
	    return l;
	if( high<low && high>mid )
	    return h;
	if ( mid<high && mid>low)
	    return m;
}
