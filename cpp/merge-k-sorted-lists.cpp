#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    priority_queue <int, vector<int>, greater<int> > pq; 
    while(t--)
    {
        int n;cin>>n;
        int v[n];
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
         for(int i=0;i<n;i++)
        {
            pq.push(v[i]);
        }
        
        
    }
    
    while(pq.size() > 0){
         cout<<pq.top()<<" ";
         pq.pop();
      }
}
