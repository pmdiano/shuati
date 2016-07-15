class Solution {
public:
    string minWindow(string s, string t) {
        int len = INT_MAX, start;
        if (s.empty() || t.empty()) {
            return "";
        }

        vector<int> dict(256, 0);
        vector<int> window(256, 0);
        int dictSize = 0, windowSize = 0, i = 0, j = 0;

        for (char c : t) {
            dict[c]++, dictSize++;
        }

        while (j < s.length()) {
            if (i < s.length() && windowSize < dictSize) {
                if (window[s[i]]++ < dict[s[i]]) {
                    windowSize++;
                }
                i++;
            } else {
                if (--window[s[j]] < dict[s[j]]) {
                    windowSize--;
                }
                j++;
            }

            if (windowSize == dictSize) {
                if (i-j < len) {
                    len = i-j;
                    start = j;
                }
            }
        }

        if (len == INT_MAX) {
            return "";
        } else {
            return s.substr(start, len);
        }
    }
};