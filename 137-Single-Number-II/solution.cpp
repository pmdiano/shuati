class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int mask = 1; mask; mask <<= 1) {
            int bit = 0;
            for (int& x : nums) {
                if (x & mask) bit++;
            }
            if (bit % 3) {
                ans |= mask;
            }
        }
        return ans;
    }
};