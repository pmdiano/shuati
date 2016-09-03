class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) return -1;

        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int total = 1; total <= amount; total++) {
            for (int i = 0; i < n; i++) {
                if (coins[i] <= total) {
                    dp[total] = min(dp[total], dp[total-coins[i]] + 1);
                }
            }
        }

        return dp[amount] <= amount ? dp[amount] : -1;
    }
};