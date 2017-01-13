class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> small(n, 1), large(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) {
                    small[i] = max(small[i], large[j] + 1);
                } else if (nums[i] > nums[j]) {
                    large[i] = max(large[i], small[j] + 1);
                }
            }
            res = max(res, small[i]);
            res = max(res, large[i]);
        }
        return res;
    }
};