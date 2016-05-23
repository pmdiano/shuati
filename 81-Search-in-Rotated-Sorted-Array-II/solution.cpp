/**
 * This explanation is pretty good:
 * http://blog.csdn.net/linhuanmars/article/details/20588511
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;

        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < nums[end]) {
                if (nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            } else if (nums[mid] > nums[end]) {
                if (nums[start] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                --end;
            }
        }

        return false;
    }
};