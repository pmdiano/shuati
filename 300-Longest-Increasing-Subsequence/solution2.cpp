class Solution {
    int findFirstGreaterThan(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (int i = 0; i < nums.size(); i++) {
            if (LIS.empty() || LIS[LIS.size() - 1] < nums[i]) {
                LIS.push_back(nums[i]);
            } else {
                int pos = findFirstGreaterThan(LIS, nums[i]);
                LIS[pos] = nums[i];
            }
        }

        return LIS.size();
    }
};