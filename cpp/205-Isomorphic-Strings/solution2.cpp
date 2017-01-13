class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        char flag1[256] = {0};
        char flag2[256] = {0};
        char map[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];
            if (flag1[sc]) {
                if (map[sc] != tc) {
                    return false;
                }
            } else {
                if (flag2[tc]) {
                    return false;
                }

                map[sc] = tc;
                flag1[sc] = 1;
                flag2[tc] = 1;
            }
        }

        return true;
    }
};