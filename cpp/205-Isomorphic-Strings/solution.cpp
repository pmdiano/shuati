class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        char flag1[256] = {0};
        char flag2[256] = {0};
        char map1[256] = {0};
        char map2[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            if (flag1[s[i]] && map1[s[i]] != t[i]) return false;
            if (flag2[t[i]] && map2[t[i]] != s[i]) return false;
            flag1[s[i]] = flag2[t[i]] = 1;
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }

        return true;
    }
};