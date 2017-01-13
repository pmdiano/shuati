class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int price = prices.empty() ? numeric_limits<int>::max() : prices[0];

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - price);
            price = min(price, prices[i]);
        }

        return profit;
    }
};
