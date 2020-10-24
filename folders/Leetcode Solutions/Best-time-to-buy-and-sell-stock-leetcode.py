def findMaxProfit(predictedSharePrices):
        max_profit, min_price = 0, float('inf')
        for price in predictedSharePrices:
            min_price = min(min_price, price)
            profit = price - min_price
            max_profit = max(max_profit, profit)
        return max_profit
