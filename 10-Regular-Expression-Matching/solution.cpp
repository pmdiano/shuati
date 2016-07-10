/**
 * Reference:
 * http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> F(m+1, vector<int>(n+1, 0));

        F[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= 1 &&  p[j-1] != '*') {
                    F[i][j] = F[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else if (j >= 2 && p[j-1] == '*') { // If p[0] is '*', won't match
                    if (F[i][j-1] || F[i][j-2]) {
                        F[i][j] = 1;
                    } else if (i > 0){
                        F[i][j] = F[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.');
                    }
                }
            }
        }

        return !!F[m][n];
    }
};
