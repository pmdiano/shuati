class Solution {
    int min3(int a, int b, int c) {
        a = min(a, b);
        a = min(a, c);
        return a;
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            f[i][0] = i;
        }

        for (int j = 1; j <= n; j++) {
            f[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    f[i][j] = f[i-1][j-1];
                } else {
                    f[i][j] = min3(f[i-1][j-1], f[i-1][j], f[i][j-1]) + 1;
                }
            }
        }

        return f[m][n];
    }
};