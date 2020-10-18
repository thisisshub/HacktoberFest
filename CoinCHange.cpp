class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {

		int n = coins.size();
		int maxc = amount + 1;
		vector<int> dp(amount + 1, maxc);

		dp[0] = 0;
		for (auto c : coins) {
			for (int i = 1; i <= amount; i++) {
				if (i - c >= 0)dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
		return dp[amount] == maxc ? -1 : dp[amount];
	}
};