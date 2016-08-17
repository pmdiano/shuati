class Solution {
    int maxLen;
    set<string> myset;

    void search(string &s, int pos, string current, int left, int maxLeft) {
        if (pos == s.length()) {
            if (left == 0 && current.length() != 0) {
                if (maxLeft > maxLen) {
                    maxLen = maxLeft;
                }
                if (maxLeft == maxLen) {
                    myset.insert(current);
                }
            }
            return;
        }

        if ((int)s.length() - pos < left) {
            // Can never match parentheses
            return;
        }
        if (maxLeft + ((int)s.length() - pos - left) / 2 < maxLen) {
            // Cannot be at least maxLen
            return;
        }

        if (s[pos] == '(') {
            search(s, pos+1, current+"(", left+1, maxLeft+1);
            search(s, pos+1, current, left, maxLeft);
        } else if (s[pos] == ')') {
            if (left > 0) {
                search(s, pos+1, current+")", left-1, maxLeft);
            }
            search(s, pos+1, current, left, maxLeft);
        } else {
            search(s, pos+1, current+string(1, s[pos]), left, maxLeft);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        myset = set<string>();
        maxLen = 0;

        string current;
        search(s, 0, current, 0, 0);

        vector<string> ans(myset.begin(), myset.end());
        if (ans.empty()) {
            ans.push_back("");
        }
        return ans;
    }
};