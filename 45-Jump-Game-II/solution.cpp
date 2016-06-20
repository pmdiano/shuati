class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int start = 0, end = 0, jumps = 0;
        while (end < nums.size() - 1) {
            jumps++;
            int farthest = end;
            for (int i = start; i <= end; i++) {
                if (i + nums[i] > farthest) {
                    farthest = i + nums[i];
                }
            }
            start = end + 1;
            end = farthest;
        }

        return jumps;
    }
};