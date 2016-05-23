/**
 * This explanation is pretty clear and neat:
 * http://blog.csdn.net/linhuanmars/article/details/20525681
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[end]) {
                // 从mid到end一定是有序的
                if (nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            } else {
                // 从start到mid一定是有序的
                if (nums[start] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }

        return -1;
    }
};
