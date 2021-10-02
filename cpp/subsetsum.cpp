#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int arr[],int n,int sum){
    int i,j;
    bool dp[n+1][sum+1];
    for(i=0;i<=n;i++)
            dp[i][0]=true;
    for(j=0;j<=sum;j++)
            dp[0][j]=false;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
int arr[]={3,3,3,3},n=sizeof(arr)/sizeof(arr[0]),sum=6;
if(subsetsum(arr,n,sum)==true)
    cout<<"TRUE";
else
    cout<<"FALSE";
return 0;

}
