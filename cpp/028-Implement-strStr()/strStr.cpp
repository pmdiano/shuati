class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= (int)haystack.length() - (int)needle.length(); ++i) {
            int j = 0;
            while (needle[j] && needle[j] == haystack[j+i]) ++j;
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};