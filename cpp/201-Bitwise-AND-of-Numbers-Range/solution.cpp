class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int mask = 1; mask; mask <<= 1) {
            if (n-m+1 <= mask && m & mask && n & mask) {
                ans |= mask;
            }
        }
        return ans;
    }
};