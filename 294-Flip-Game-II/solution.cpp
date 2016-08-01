class Solution {
public:
    bool canWin(string s) {
        for (int i = 0; i < (int)s.length() - 1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string t = s;
                t[i] = '-', t[i+1] = '-';
                if (!canWin(t)) return true;
            }
        }
        return false;
    }
};