class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[2] = {0};
        for (int i = 0; i < nums.size(); i++) {
            dp[i%2] = max(dp[i%2] + nums[i], dp[(i+1)%2]);
        }
        return max(dp[0], dp[1]);
    }
};