/*
Input:
1
6
1 2 3 1 4 2
Output:
1 2 3 4
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	   for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    bool val[101];
	    memset(val,true,sizeof(val));
	    
	    for(int i=0;i<n;i++){
	        if(val[arr[i]]){
	            cout<<arr[i]<<" ";
	            val[arr[i]] = false;
	        }
	    }
	    cout<<endl;
	}
}
