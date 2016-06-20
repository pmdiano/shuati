class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        vector<int> f(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                }
            }
        }

        int ans = f[0];
        for (int i = 1; i < n; i++) {
            if (f[i] > ans) {
                ans = f[i];
            }
        }

        return ans;
    }
};