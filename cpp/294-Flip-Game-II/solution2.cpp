class Solution {
    bool helper(string& s) {
        for (int i = 0; i < (int)s.length()-1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = '-', s[i+1] = '-';
                bool win = !helper(s);
                s[i] = '+', s[i+1] = '+';
                if (win) return true;
            }
        }
        return false;
    }
public:
    bool canWin(string s) {
        return helper(s);
    }
};