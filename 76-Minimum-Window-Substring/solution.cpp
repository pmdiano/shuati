class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        if (s.empty() || t.empty()) {
            return result;
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
                string str = s.substr(j, i-j);
                if (result == "" || str.length() < result.length()) {
                    result = str;
                }
            }
        }

        return result;
    }
};