class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }

        int n = nums.size();
        vector<unsigned char> f(n, 0);
        f[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && f[i]) {
                memset(&f[i+1], 1, min(n-i-1, nums[i]));
            }
        }

        return !!f[n-1];
    }
};