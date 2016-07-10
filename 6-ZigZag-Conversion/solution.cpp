class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }

        string t(s.length(), '0');

        for (int row = 0, i = 0; row < numRows; row++) {
            if (row == 0 || row == numRows-1) {
                int interval = 2 * (numRows-1);
                for (int j = row; j < s.length(); j += interval) {
                    t[i++] = s[j];
                }
            } else {
                int interval1 = 2 * (numRows-1-row);
                int interval2 = 2 * (numRows-1);
                for (int j = row; j < s.length(); j += interval2) {
                    t[i++] = s[j];
                    if (j+interval1 < s.length()) {
                        t[i++] = s[j+interval1];
                    }
                }
            }
        }

        return t;
    }
};