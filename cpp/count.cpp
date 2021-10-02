#include<iostream>
using namespace std;

#include <algorithm>
int platformsNeeded(int arrival[], int departure[], int n) {
    /*
     * Don't write main().
     * Don't read input, it is passed as function argument.
     * Don't print anything just return integer value.
     */
    int platform=1, result=1;
    int i=1, j=0;
    sort(arrival, arrival+n);
    sort(departure, departure+n);
    while (i<n && j<n)
    {
        if (arrival[i]<=departure[j])
        {
            platform++;
            i++;
            if (platform>result)
                result=platform;
        }
        else
        {
            platform--;
            j++;
        }  
    }
    return result;
}


int main()
{
	int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
    {
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);
}
