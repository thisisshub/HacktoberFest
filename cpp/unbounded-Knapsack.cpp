#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    cin>>val[i];
    
    for(int i=0;i<n;i++)
    cin>>wt[i];
    
    int cap;
    cin>>cap;
    
    int *dp = new int [cap+1];
    dp[0]=0;
    int max=0;
    for(int i=1;i<cap+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i]=max;
            if(wt[j]<=i)
            {
                int rbag=i-wt[j];
                int rbagv=dp[rbag];
                int tbagv=rbagv+val[j];
                
                if(max<tbagv)
                {
                    max=tbagv;
                }
            }
        }
    }
   
    cout<<dp[cap]<<endl;
    
}
