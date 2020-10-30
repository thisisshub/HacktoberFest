#include "../libraries/mixin.h"

void _sort(vector<lld> &arr,lld low,lld hi)
{

    if(hi<=low)
        return;
    lld i = low + 1, j = hi, div = low;
    while(true)
    {

        while(arr[i] == arr[div] && i <= j)
            i++;
        while(arr[j] == arr[div] && j >= i)
            j--;
        if(j < i)
        {

            swap(arr[j],arr[div]);
            div = j ;
            break;
        }
        else if (arr[j]<arr[div])
        {
            swap(arr[j],arr[i++]);
        }
        else if(arr[i]>arr[div])
        {
            swap(arr[j--],arr[i]);
        }
        else
        {
            i++;
        }
        //printArr(arr); cout<<endl;
    }
    _sort(arr,low,div-1);
    _sort(arr,div+1,hi);



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
        lld t = rand() % 40;
        arr[i] = t;
        //cout<<t<<" ";
    }
    cout<<"\n------Start------"<<endl;
    _sort(arr,0,n-1);

    cout<<"\n------Result------";
    printf("      Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    //printArr(arr);
}
