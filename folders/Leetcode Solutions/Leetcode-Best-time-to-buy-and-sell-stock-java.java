class Solution {

    // You may change this function parameters
    static int findMaxProfit(int numOfPredictedDays, int[] predictedSharePrices) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for(int i = 0;i<numOfPredictedDays;i++){
            if (predictedSharePrices[i] < minprice)
                minprice = predictedSharePrices[i];
            else if (predictedSharePrices[i] - minprice > maxprofit)
                maxprofit = predictedSharePrices[i] - minprice;
        }
        return maxprofit;
    }
}
