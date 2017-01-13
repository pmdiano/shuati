class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int minCost = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minCost);
            minCost = min(minCost, prices[i]);
        }
        
        return maxProfit;
    }
};