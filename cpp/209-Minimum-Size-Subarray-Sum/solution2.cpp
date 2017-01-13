class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, ans = numeric_limits<int>::max();

        while (i < nums.size()) {
            if (sum >= s) {
                ans = min(ans, j-i);
                sum -= nums[i++];
            } else {
                if (j < nums.size()) {
                    sum += nums[j++];
                } else {
                    break;
                }
            }
        }

        return ans == numeric_limits<int>::max() ? 0 : ans;
    }
};