class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.empty()) {
            return result;
        }

        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        result[0] = start;
        
        start = 0;
        end = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        result[1] = end;
        
        if (result[0] > result[1]) {
            result[0] = -1;
            result[1] = -1;
        }

        return result;
    }
};
