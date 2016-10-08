class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right-1) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid;
            else
                right--;
        }
        return min(nums[left], nums[right]);
    }
};