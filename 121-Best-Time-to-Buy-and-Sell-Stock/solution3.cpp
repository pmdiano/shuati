class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 1;
        if (prices.empty() || k <= 0) {
            return 0;
        }

        if (2 * k >= prices.size()) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] - prices[i-1] > 0) {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }

        vector<int> local(prices.size(), 0);
        vector<int> global(prices.size(), 0);

        for (; k > 0; k--) {
            for (int i = 1; i < prices.size(); i++) {
                int diff = prices[i] - prices[i-1];
                local[i] = max(global[i], local[i-1] + diff);
                global[i] = max(global[i-1], local[i]);
            }
        }

        return global[prices.size() - 1];
    }
};
