class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> F(n+1, 0);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int j = i-1-F[i-1];
            if (j >= 1 && s[j-1] == '(' && s[i-1] == ')') {
                F[i] = F[j-1] + F[i-1] + 2;
                ans = max(ans, F[i]);
            }
        }

        return ans;
    }
};