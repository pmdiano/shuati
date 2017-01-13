class Solution {

public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            if ((mid == 0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] > nums[mid+1]))
                break;
            else if (mid == 0 || nums[mid] < nums[mid+1])
                start = mid+1;
            else
                end = mid-1;
        }
        
        return mid;
    }
};