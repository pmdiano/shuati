class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), mask = 1, ans = 0;
        while (mask) {
            int count = 0;
            for (int x : nums) {
                if (x & mask) count++;
            }
            if (count > n/2) ans |= mask;
            mask <<= 1;
        }
        return ans;
    }
};