class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length(), i, j;
        if (m-n >= 2 || m-n <= -2) {
            return false;
        }

        bool edit = false;
        for (i=j=0; i<m && j<n; ) {
            if (s[i] == t[j]) {
                i++, j++;
            } else {
                if (edit) return false;
                edit = true;
                if (m == n) { i++, j++; }
                else if (m > n) { i++; }
                else { j++; }
            }
        }

        if (i<m || j<n) edit = true;

        return edit;
    }
};