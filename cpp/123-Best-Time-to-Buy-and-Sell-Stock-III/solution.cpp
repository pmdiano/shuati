class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> forward(prices.size(), 0);
        vector<int> backward(prices.size(), 0);
        
        int cost = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            forward[i] = max(forward[i-1], prices[i] - cost);
            cost = min(prices[i], cost);
        }

        int sale = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; i--) {
            backward[i] = max(backward[i+1], sale - prices[i]);
            sale = max(prices[i], sale);
        }

        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, forward[i] + backward[i]);
        }

        return profit;
    }
};