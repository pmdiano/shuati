class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> local(n+3, 0);
        for (int i = 3; i < n+3; i++) {
            local[i] = max(local[i-2], local[i-3]) + nums[i-3];
        }
        return max(local[n+1], local[n+2]);
    }
};