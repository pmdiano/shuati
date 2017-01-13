class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int hash[256] = {0};
        for (char c : s) {
            hash[c]++;
        }
        for (char c : t) {
            if (--hash[c] < 0) {
                return false;
            }
        }
        return true;
    }
};