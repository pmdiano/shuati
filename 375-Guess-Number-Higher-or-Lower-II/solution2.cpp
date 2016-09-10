class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
        for (int len = 2; len <= n; len++) {
            for (int start=1, end=start+len-1; end <= n; start++, end++) {
                dp[start][end] = INT_MAX;
                for (int guess = start; guess <= end; guess++) {
                    int cost = guess + max(dp[start][guess-1], dp[guess+1][end]);
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }
        return dp[1][n];
    }
};