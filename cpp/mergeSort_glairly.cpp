#include "../libraries/mixin.h"
#include <time.h>
#define oper less



void printArr(vector<lld> arr)
{
    for(auto &i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


void _merge(vector<lld> &arr,lld low,lld mid,lld hi)
{
    vector <lld> dup  = arr;

    for(lld i = low, j = mid + 1,k = low; k<=hi ; ++k)
    {
        // if low is exhausted

        if(i > mid)
        {
            arr[k] = dup[j++];
        }
        // if hi is exhausted
        else if(j > hi)
        {
            arr[k] = dup[i++];
        }
        // compare
        else if(dup[j]<dup[i])
        {
            arr[k] = dup[j++];
        }
        else
        {
            arr[k] = dup[i++];
        }

    }
}

void _sort(vector<lld> &arr,lld low,lld hi)
{
    if(hi <= low)
        return;
    // left
    lld mid = low + (hi-low)/2;
    _sort(arr,low,mid);
    // right
    _sort(arr,mid+1,hi);
    _merge(arr,low,mid,hi);
}


int main()
{

    lld n;
    cin>>n;
    srand(time(NULL));
    clock_t tStart = clock();
    vector<lld> arr(n);
    for(lld i = 0 ; i < n ; i++)
    {
        lld t = rand() % 20;
        arr[i] = t;
    }
    _sort(arr,0,n-1);
    printf("\nTime taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout<<"\n------Result------"<<endl;
    //printArr(arr);
}
