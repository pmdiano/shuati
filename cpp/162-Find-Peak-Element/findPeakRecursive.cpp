class Solution {
    int findPeak(vector<int>& nums, int start, int end) {
        int mid = start + (end - start) / 2;
        if ((mid == start || nums[mid] > nums[mid-1]) && (mid == end || nums[mid] > nums[mid+1]))
            return mid;
        else if (mid == start || nums[mid] < nums[mid+1])
            return findPeak(nums, mid+1, end);
        else
            return findPeak(nums, start, mid-1);
    }

public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        return findPeak(nums, 0, nums.size() - 1);
    }
};