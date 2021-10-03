#include<iostream>
#include <unordered_map>
#include <set>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;cin>>k;
     priority_queue <int, vector<int>, greater<int> > pq; 

    for (int i = 0; i < n; i++)
    {
        if(i<k)
        {
            pq.push(a[i]);
        }
        
        else
        {
            if(a[i]>pq.top())
            {
                pq.pop();
                pq.push(a[i]);
            }
        }
    }
    
 while(pq.size() > 0){
         cout<<pq.top()<<endl;
         pq.pop();
      }
    
}
