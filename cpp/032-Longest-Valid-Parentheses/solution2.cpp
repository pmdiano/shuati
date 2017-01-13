class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, int>> stk;    // first: index; second: 0 if '(', 1 if ')'
        int len = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(make_pair(i, 0));
            } else {
                if (stk.empty() || stk.top().second == 1) {
                    stk.push(make_pair(i, 1));
                } else {
                    stk.pop();
                    len = stk.empty() ? i+1 : i-stk.top().first;
                    maxLen = max(len, maxLen);
                }
            }
        }

        return maxLen;
    }
};