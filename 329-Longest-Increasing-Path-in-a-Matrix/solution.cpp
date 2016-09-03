class Solution {
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int res = 1, m = matrix.size(), n = matrix[0].size();
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto d : dirs) {
            int inext = i + d.first, jnext = j + d.second;
            if (inext < 0 || inext >= m || jnext < 0 || jnext >= n || matrix[inext][jnext] <= matrix[i][j]) {
                continue;
            }
            res = max(res, 1 + dfs(matrix, dp, inext, jnext));
        }

        dp[i][j] = res;
        return res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }

        return res;
    }
};