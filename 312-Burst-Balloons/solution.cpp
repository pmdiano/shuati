class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int len = 1; len <= n; len++) {
            for (int left = 1, right = left + len - 1; right <= n; ++left, ++right) {
                for (int k = left; k <= right; k++) {
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]
                        *nums[right+1] + dp[left][k-1] + dp[k+1][right]);
                }
            }
        }

        return dp[1][n];
    }
};