class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2, 0);

        if (n > 0) res[0] = nums[0];
        if (n > 1) res[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            res[i%2] = max(res[i%2] + nums[i], res[(i-1)%2]);
        }

        return max(res[0], res[1]);
    }
};