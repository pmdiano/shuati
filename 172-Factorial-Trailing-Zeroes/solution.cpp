class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        n = n < 0 ? -n : n;
        n /= 5;
        while (n) {
            ans += n;
            n /= 5;
        }
        return ans;
    }
};