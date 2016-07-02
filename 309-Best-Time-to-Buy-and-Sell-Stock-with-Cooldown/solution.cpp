class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> local(prices.size(), 0);
        vector<int> global(prices.size(), 0);

        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            local[i] = max(local[i-1] + diff, diff);
            if (i>=3) {
                local[i] = max(local[i], global[i-3] + diff);
            }

            global[i] = max(global[i-1], local[i]);
        }

        return global[prices.size() - 1];
    }
};