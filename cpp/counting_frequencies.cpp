// counting frequencies in time complexity: O(n) and space O(1)
#include<bits/stdc++.h>
using namespace std;

void count_freq(int arr[],int n)
{
    unordered_map<int,int> freq;
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    for(auto x:freq)   
        cout<<x.first<<" : "<<x.second<<endl;
}
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    count_freq(arr,n);
    return 0;
}
