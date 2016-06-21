class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        int m = s1.length();
        int n = s2.length();
        vector<vector<unsigned char>> f(m+1, vector<unsigned char>(n+1, 0));

        f[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            f[i][0] = f[i-1][0] & (s1[i-1] == s3[i-1]);
        }
        for (int j = 1; j <= n; j++) {
            f[0][j] = f[0][j-1] & (s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                const char c1 = s1[i-1];
                const char c2 = s2[j-1];
                const char c3 = s3[i+j-1];

                if (c3 == c1 && c3 == c2) {
                    f[i][j] = f[i-1][j] | f[i][j-1];
                } else if (c3 == c1) {
                    f[i][j] = f[i-1][j];
                } else if (c3 == c2) {
                    f[i][j] = f[i][j-1];
                }
            }
        }

        return !!f[m][n];
    }
};
