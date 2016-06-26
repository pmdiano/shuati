class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = s.length();
        const int m = p.length();
        vector<vector<bool>> F(n+1, vector<bool>(m+1, false));

        F[0][0] = true;
        for (int j = 1; j <= m && p[j-1] == '*'; j++) {
            F[0][j] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                switch(p[j-1]) {
                    case '*':
                        F[i][j] = F[i-1][j-1] || F[i][j-1] || F[i-1][j];
                        break;

                    case '?':
                        F[i][j] = F[i-1][j-1];
                        break;

                    default:
                        F[i][j] = F[i-1][j-1] && s[i-1] == p[j-1];
                }
            }
        }

        return F[n][m];
    }
};
