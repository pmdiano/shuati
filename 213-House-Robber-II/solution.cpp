class Solution {
    int rob2(vector<int>& nums, int start, int end) {
        int F[2] = {0};
        for (int i = start; i <= end; i++) {
            F[i%2] = max(F[i%2] + nums[i], F[(i+1)%2]);
        }
        return max(F[0], F[1]);
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob2(nums, 0, nums.size()-2), rob2(nums, 1, nums.size()-1));
    }
};