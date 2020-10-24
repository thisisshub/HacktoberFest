/**
 * Author: Siddhant Pandya
 * Problem: 416. Partition Equal Subset Sum
 */

class Solution {
public:
    int oor(int i, int j)
    {
	    if(i==1 || j==1)
	    {
		    return 1;
	    }
	    return 0;
    }
    
    bool canPartition(vector<int>& arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
	int sum=0;
	
    for(int x=0;x<n;x++)
	{
		sum+=arr[x];
	}
        
	if(sum%2!=0)
	{
		return false;
	}
	else
	{
		sum/=2;
		int dp[n+1][sum+1];
		
		//initialisation
		for(int x=0;x<=sum;x++)
		{
			dp[0][x]=0;
		}
		for(int x=0;x<=n;x++)
		{
			dp[x][0]=1;
		}
		
		//table filling
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=sum;y++)
			{
				if(arr[x-1]<=y)
				{
					dp[x][y]= oor(dp[x-1][y-arr[x-1]],dp[x-1][y]);
				}
				else
				{
					dp[x][y]=dp[x-1][y];
				}
			}
		}
		
		if(dp[n][sum]==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
    }
};