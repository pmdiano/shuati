class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> F(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '0') {
                    F[i][j] = 0;
                } else {
                    F[i][j] = min(F[i-1][j-1], min(F[i][j-1], F[i-1][j])) + 1;
                    ans = max(ans, F[i][j]);
                }
            }
        }

        return ans * ans;
    }
};
