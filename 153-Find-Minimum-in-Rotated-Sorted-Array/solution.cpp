/**
 * This is my own solution. Not as good as the other one.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if ((mid == 0 || nums[mid] < nums[mid-1]) &&
                (mid == nums.size() - 1 || nums[mid] < nums[mid+1]))
                return nums[mid];
            else if (nums[mid] < nums[end])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};