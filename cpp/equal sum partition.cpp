
#include<bits/stdc++.h>
using namespace std;
int findmin(int arr[],int n){
    int i,j;
    int sum=0;
    for(i=0;i<n;i++)
        sum+=arr[i];

    bool dp[n+1][sum+1];
    for(j=0;j<=sum;j++)
            dp[0][j]=false;

    for(i=0;i<=n;i++)
            dp[i][0]=true;
    dp[0][0]=true;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];


        }
    }
    int mn=INT_MAX;
    for(j=sum/2;j>=0;j--)
    {
        if(dp[n][j]==true)
            mn=sum-2*j;
            break;
    }

    return mn;
}

int main(){
int i;
int arr[]={1,6,11,5},n=sizeof(arr)/sizeof(arr[0]),sum=0;
for(i=0;i<n;i++)
    sum+=arr[i];
cout<<(findmin(arr,n));

return 0;

}
