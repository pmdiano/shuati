class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int i = 0, j = 0, len = 0;
        while (j < s.size()) {
            if (!hash[s[j]]) {
                hash[s[j]]++;
                j++;
                len = max(len, j-i);
            } else {
                while (s[i] != s[j]) {
                    hash[s[i++]]--;
                }
                i++, j++;
            }
        }
        return len;
    }
};