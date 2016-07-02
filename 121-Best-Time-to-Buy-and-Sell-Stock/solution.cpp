class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int price = numeric_limits<int>::max();
        for (int i = 0; i < prices.size(); i++) {
            if (i > 0) {
                profit = max(profit, prices[i] - price);
            }
            price = min(price, prices[i]);
        }
        return profit;
    }
};