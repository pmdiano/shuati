class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);

        int size = 1, id = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (size < dp[i]) {
                size = dp[i];
                id = i;
            }
        }

        while (id < nums.size() && id != -1) {
            res.push_back(nums[id]);
            id = pre[id];
        }
        return res;
    }
};