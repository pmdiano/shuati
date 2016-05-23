class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int start = 0;
        int end = nums.size() - 1;
        int mid;
        int minVal = nums[0];

        while (start < end - 1) {
            mid = start + (end - start) / 2;
            if (nums[start] < nums[mid]) {
                minVal = min(minVal, nums[start]);
                start = mid + 1;
            } else if (nums[start] > nums[mid]) {
                minVal = min(minVal, nums[mid]);
                end = mid - 1;
            } else {
                --start;
            }
        }

        minVal = min(minVal, nums[start]);
        minVal = min(minVal, nums[end]);
        return minVal;
    }
};