class Solution {
    bool isScrambleHelper(const char* s1, const char* s2, int len) {
        if (len <= 0) {
            return true;
        }

        int i = 0;
        for (; i < len && s1[i] == s2[i]; i++);
        if (i == len) {
            return true;
        }

        int count[256] = {0};
        for (i = 0; i < len; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        for (int n = 1; n < len; n++) {
            if (isScrambleHelper(s1, s2, n) && isScrambleHelper(s1+n, s2+n, len-n)) {
                return true;
            }
            if (isScrambleHelper(s1, s2+len-n, n) && isScrambleHelper(s1+n, s2, len-n)) {
                return true;
            }
        }

        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        return isScrambleHelper(s1.c_str(), s2.c_str(), s1.length());
    }
};