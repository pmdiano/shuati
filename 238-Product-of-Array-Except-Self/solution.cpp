class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }

        // forward
        vector<int> output(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            output[i] = output[i-1] * nums[i-1];
        }

        // backward
        int backward = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] = output[i] * backward;
            backward *= nums[i];
        }

        return output;
    }
};