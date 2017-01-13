class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = 0, count = 0, ans = 0;
        int window[256] = {0};
        while (i < s.length()) {
            if (window[s[i]] || count < 2) {
                if (window[s[i++]]++ == 0) {
                    count++;
                }
                if (i-j > ans) {
                    ans = i-j;
                }
            } else {
                if (--window[s[j++]] == 0) {
                    count--;
                }
            }
        }
        return ans;
    }
};