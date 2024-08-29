class Solution {
public:

void findMaxProfitRE(vector<int> &prices, int index, int&minPrice, int &maxProfit) {

    // base case;
    if(index >= prices.size()) {
        return;
    }

    
    if(prices[index] < minPrice) minPrice = prices[index];
    int totalProfit = prices[index] - minPrice;
    if(totalProfit > maxProfit) maxProfit = totalProfit;


    findMaxProfitRE(prices, index+1, minPrice, maxProfit);
}
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        int index = 0;

        findMaxProfitRE(prices, index,minPrice,maxProfit);

        return maxProfit;
    }
};