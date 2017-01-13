class Solution {
    // nums is continuously increasing array
    // find first position where nums[i] >= target
    int binarySearch(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        vector<int> presum(n+1, 0);
        for (int i = 0; i < n; i++) {
            presum[i+1] = presum[i] + nums[i];
        }

        int ans = numeric_limits<int>::max();
        bool found = false;

        for (int i = 0; i < n; i++) {
            int end = binarySearch(presum, s+presum[i]);
            if (end < presum.size()) {
                found = true;
                ans = min(ans, end-i);
            }
        }

        return found ? ans : 0;
    }
};