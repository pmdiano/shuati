class Solution {
    // abc --> ^#a#b#c#$
    string preprocess(string& s) {
        string t(s.length() * 2 + 3, '#');
        t[0] = '^';
        t[t.length() - 1] = '$';

        for (int i = 0, j = 2; i < s.length(); i++, j+=2) {
            t[j] = s[i];
        }

        return t;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        string t = preprocess(s);
        vector<int> P(t.length(), 0);
        int C = 0, R = 0;
        int index = 0, ans = -1;

        for (int i = 1; i < t.length(); i++) {
            int mirr = 2 * C - P[i];

            if (i < R) {
                P[i] = min(R-i, P[mirr]);
            }

            while (t[i + (1 + P[i])] == t[i - (1 + P[i])]) {
                P[i]++;
            }

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            if (P[i] > ans) {
                ans = P[i];
                index = i;
            }
        }

        return s.substr((index-ans)/2, ans);
    }
};