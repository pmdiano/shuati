class Solution {
    bool search(vector<int>& nums, int start, int target) {
        if (target == 0) return true;
        if (target < nums[start]) return false;
        for (int i = start; i < nums.size(); i++) {
            if (search(nums, i+1, target - nums[i])) {
                return true;
            }
        }
        return false;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sort(nums.begin(), nums.end());
        return search(nums, 0, sum / 2);
    }
};
