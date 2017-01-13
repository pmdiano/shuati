class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0, j = 0, count = 0, ans = 0;
        int window[256] = {0};
        while (i < s.length()) {
            if (window[s[i]] || count < k) {
                if (window[s[i++]]++ == 0) {
                    count++;
                }
                if (ans < i-j) {
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