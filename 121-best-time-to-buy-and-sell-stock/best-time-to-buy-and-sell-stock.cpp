class Solution {
public:

 int findMaxProfitRE(vector<int> &prices) {

    // track minimum price
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i=1; i<prices.size(); i++) {
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);

        // update minimum price
        minPrice = min(minPrice, prices[i]);
    }
    
    return maxProfit;
 }
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        
        int maxProfit = findMaxProfitRE(prices);

        return maxProfit;
    }
};