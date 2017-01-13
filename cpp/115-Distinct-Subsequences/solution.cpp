class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.length() < t.length()) {
            return 0;
        }

        int m = t.length();
        int n = s.length();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));

        for (int j = 0; j <= n; j++) {
            f[0][j] = 1;
        }

        for (int i = 1; i <= m; i++) {
            f[i][i-1] = 0;
            for (int j = i; j <= n; j++) {
                f[i][j] = f[i][j-1];
                if (t[i-1] == s[j-1]) {
                    f[i][j] += f[i-1][j-1];
                }
            }
        }

        return f[m][n];
    }
};