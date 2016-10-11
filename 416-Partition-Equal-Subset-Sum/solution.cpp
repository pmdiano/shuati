class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2) return false;
        sum /= 2;

        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int s = 0; s <= sum - x; s++) {
                if (dp[s]) dp[s+x] = 1;
            }
            if (dp[sum]) return true;
        }
        return false;
    }
};