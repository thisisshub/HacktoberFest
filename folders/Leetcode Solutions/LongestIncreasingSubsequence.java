import java.util.*;
public class LongestIncreasingSubsequence {

	public static int solve(int arr[],int n) {
		
		int dp[]=new int[n];
		
		for(int i=0;i<n;i++) {
			dp[i]=1;
			for(int j=i-1;j>=0;j--) {
				if(arr[j]<arr[i]) {
					dp[i]=Math.max(dp[i], 1+dp[j]);
				}
			}
		}
		
		int max=1;
		for(int i=0;i<n;i++) {
			max=Math.max(max,dp[i]);
		}
		
		return max;
	}
	
	public static void main(String[] args) {
		
	}
}
