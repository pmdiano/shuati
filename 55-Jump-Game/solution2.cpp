class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }

        int farthest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (farthest >= i && farthest < i + nums[i]) {
                farthest = i + nums[i];
            }
        }

        return farthest >= nums.size() - 1;
    }
};