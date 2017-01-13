class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        // local[i] means the maximum possible profit from day 0~i, with a guaranteed sell on day i
        // global[i] means the maximum possible profit from day 0~i
        vector<int> local(prices.size(), 0);
        vector<int> global(prices.size(), 0);

        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            local[i] = max(local[i-1] + diff, diff);
            if (i>3) {
                // With cool down, sell on day i, buy on day i-1, cooldown on day i-2, sell on day i-3 (or earlier)
                local[i] = max(local[i], global[i-3] + diff);
            }

            global[i] = max(global[i-1], local[i]);
        }

        return global[prices.size() - 1];
    }
};