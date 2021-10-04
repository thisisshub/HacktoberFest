/*
absolute difference of the array pairs all possible combination
Input:
n=10
arr[]= 12,23,34,45,56,67,78,89,100,20
output:
89 100
97

Input:
n=5
arr[]= 10,20,30,40,50
output:
10,50
4
*/
#include <bits/stdc++.h>
using namespace std;

int reversed(int m)
{

             string str = to_string(m);
        string rev = string(str.rbegin(),str.rend());
             m =stoi(rev);
             return m;
}

// Function to find a pair with the given difference in an array.
// This method does not handle duplicates in the array
void findPair(int arr[], int n)
{
    // array is unsorted

    // take an empty set
   vector<pair<pair<int,int>,pair<int,int>>> set;

     for (int i = 0; i < n; i++)
    {
        // See if there is a pair of this picked element
        for (int j = i+1; j < n; j++)
         set.push_back(make_pair(make_pair(reversed(arr[i]),reversed(arr[j])),make_pair(arr[i],arr[j])));
    }
    // long long maxs= *max_element(set.begin(),set.end());
    long long ma=-999;
    vector<pair<pair<int,int>,pair<int,int>>>::iterator it;
    for (auto itr = set.begin(); itr != set.end(); itr++)
    {
       if(ma < abs((itr->first.first)-itr->first.second))
       {
           it=itr;
           ma=abs(itr->first.first-itr->first.second);
           }
    }
    cout<<it->second.first<<" "<<it->second.second;
    cout<<endl<<ma;

}

int main()
{
    int arr[] = { 12,23,34,45,56,67,78,89,100,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int diff = 3;

//     int n;
//  cin>>n;
//     int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];

    findPair(arr, n);

    return 0;
}
