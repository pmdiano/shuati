class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int sum = 1; sum <= target; sum++) {
            for (int a : nums) {
                if (a <= sum) {
                    dp[sum] += dp[sum - a];
                }
            }
        }
        return dp[target];
    }
};