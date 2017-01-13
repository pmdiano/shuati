class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = numeric_limits<int>::min();
        unordered_map<int, int> hash;
        hash[0] = -1;

        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.find(sum - k) != hash.end()) {
                ans = max(ans, i - hash[sum - k]);
            }
            if (hash.find(sum) == hash.end()) {
                hash[sum] = i;
            }
        }

        return ans == numeric_limits<int>::min() ? 0 : ans;
    }
};