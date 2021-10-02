#include<bits/stdc++.h>
using namespace std;
int subsetsum(int arr[],int n,int sum){
    int i,j;
    int dp[n+1][sum+1];
    for(j=0;j<=sum;j++)
            dp[0][j]=0;

    for(i=0;i<=n;i++)
            dp[i][0]=1;
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
int arr[]={1,1,1,1},n=sizeof(arr)/sizeof(arr[0]),sum=1;
cout<<(subsetsum(arr,n,sum));

return 0;

}
