class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        int hash[256] = {0};
        for (char c : s) {
            if (hash[c]) {
                len += 2;
                hash[c] = 0;
            } else {
                hash[c] = 1;
            }
        }
        for (int i = 0; i < 256; i++) {
            if (hash[i]) {
                len++;
                break;
            }
        }
        return len;
    }
};