class Solution {
    bool isValidNumber(string& s, int& i, int j, bool might_have_e, bool might_have_dot) {
        if (s[i] == '+' || s[i] == '-') i++;
        bool has_number = false, has_dot = false;
        while (i <= j) {
            if ('0' <= s[i] && s[i] <= '9') {
                has_number = true;
                i++;
            } else if (s[i] == 'e') {
                return might_have_e && has_number;
            } else if (s[i] == '.') {
                if (has_dot || !might_have_dot) {
                    return false;
                }
                has_dot = true;
                i++;
            } else {
                return false;
            }
        }
        return has_number;
    }

public:
    bool isNumber(string s) {
        int i = 0, j = s.length() - 1;
        while (s[i] && (s[i] == ' ' || s[i] == '\t')) i++;
        while (j >= 0 && (s[j] == ' ' || s[j] == '\t')) j--;
        if (i > j) return false;

        if (!isValidNumber(s, i, j, true, true)) {
            return false;
        }

        if (i == j+1) {
            return true;
        }

        // s[i] == 'e'
        i++;
        return isValidNumber(s, i, j, false, false);
    }
};