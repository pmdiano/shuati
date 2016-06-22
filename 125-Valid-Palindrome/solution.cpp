class Solution {
    bool isAlphaNumeric(const char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool ignoreCaseEqual(char a, char b) {
        if (a >= 'a') {
            a -= ('a' - 'A');
        }
        if (b >= 'a') {
            b -= ('a' - 'A');
        }
        return a == b;
    }

public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isAlphaNumeric(s[i])) {
                i++;
            } else if (!isAlphaNumeric(s[j])) {
                j--;
            } else if (!ignoreCaseEqual(s[i], s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};