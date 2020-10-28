#include<iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n1,n2,result=0;
	    string s1,s2;
	    cin>>n1>>n2;
	    int dp[n1+1][n2+1];
	    cin>>s1>>s2;
	    for(int i=0;i<=n1;i++){
	        for(int j=0;j<=n2;j++){
	            if(i==0 || j==0)
	             dp[i][j]=0;
	            else if(s1[i-1]==s2[j-1]){
	                dp[i][j]=1+dp[i-1][j-1];
	                result=std::max(result,dp[i][j]);
	            }
	            else
	            dp[i][j]=0;
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}
