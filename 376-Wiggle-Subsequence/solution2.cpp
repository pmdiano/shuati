class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), large = 1, small = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                large = small + 1;
            } else if (nums[i] < nums[i-1]) {
                small = large + 1;
            }
        }
        return min(n, max(large, small));
    }
};