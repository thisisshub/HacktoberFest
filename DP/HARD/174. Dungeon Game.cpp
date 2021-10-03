class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size();
        int m = d[0].size();
        int dp[n][m];
        dp[n-1][m-1] = min(0,d[n-1][m-1]);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j == m-1 && i == n-1)
                    continue;
                else if(j == m-1)
                    dp[i][j] = min(0 , dp[i+1][j] + d[i][j]);
                else if(i == n-1)
                    dp[i][j] = min(0 , dp[i][j+1] + d[i][j]);
                else
                    dp[i][j] = min(0 , max(dp[i+1][j] , dp[i][j+1]) + d[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return abs(dp[0][0]) + 1;
    }
};