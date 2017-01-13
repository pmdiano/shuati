class Solution {
public:
    int titleToNumber(string s) {
        int base = 1, ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            ans += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return ans;
    }
};