class Solution {
public:
    int integerBreak(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
                dp[i] = max(dp[i], j * dp[i-j]);
                dp[i] = max(dp[i], dp[j] * (i-j));
                dp[i] = max(dp[i], j * (i-j));
            }
        }
        return dp[n];
    }
};