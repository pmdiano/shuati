class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int i = 0, j = 0, len = 0;

        for (; i < s.length(); i++) {
            if (!hash[s[i]]) {
                hash[s[i]] = 1;
                len = max(i-j+1, len);
            } else {
                while (s[j] != s[i]) {
                    hash[s[j]] = 0;
                    j++;
                }
                j++;
            }
        }

        return len;
    }
};