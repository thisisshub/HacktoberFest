/*std::max_element is defined inside the header file and it returns an iterator pointing to the element with the largest 
value in the range [first, last).*/
/*
Given an increasing sequence a[], we need to find the K-th missing contiguous element in the increasing sequence 
which is not present in the sequence. If no k-th missing element is there output -1.
*/
/*
Input
2
5 2
1 3 4 5 7
6 2 
1 2 3 4 5 6 
Output
6
-1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,f=0,c=0,k,max,min;
	    cin>>n>>k;int a[n];
	    set<int> hash;
	    for(int i=0;i<n;i++)
	    { cin>>a[i];
	     hash.insert(a[i]);}
	    max=*max_element(a,a+n);
	    min=*min_element(a,a+n);
	    for(int i=min+1;i<max;i++)
	     {if(hash.find(i)==hash.end())
	      c++;
	     if(c==k)
	      {cout<<i<<endl;f=1;break;}}
	     if(!f)
	     cout<<-1<<endl;
	}
	return 0;
}
