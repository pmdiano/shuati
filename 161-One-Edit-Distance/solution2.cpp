class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (abs(m-n) > 1) return false;
        for (int i = 0; i < min(m, n); i++) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) return s.substr(i+1) == t.substr(i+1);
                else if (s.size() < t.size()) return s.substr(i) == t.substr(i+1);
                else return s.substr(i+1) == t.substr(i);
            }
        }
        return abs(m-n) == 1;
    }
};