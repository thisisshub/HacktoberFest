"""
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
"""
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if n < 2: 
            return 0
        if k >= n // 2: # problem 122. Best Time to Buy and Sell Stock II
            max_profit = 0
            for i in range(n - 1):
                max_profit += max(prices[i+1] - prices[i], 0)
            return max_profit
        dp = [[0 for _ in range(k+1)] for _ in range(n)]
        for k1 in range(1, k+1):
            local_max = -prices[0]
            for i in range(1, n):
                dp[i][k1] = max(dp[i-1][k1], prices[i] + local_max)
                local_max = max(local_max, dp[i-1][k1-1] - prices[i])
        return dp[n-1][k]
