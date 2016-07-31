class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1, 0);
        while (dp.size() <= n) {
            int m = dp.size(), val = INT_MAX;
            for (int i = 1; i * i <= m; i++) {
                val = min(val, 1 + dp[m - i * i]);
            }
            dp.push_back(val);
        }
        return dp.back();
    }
};