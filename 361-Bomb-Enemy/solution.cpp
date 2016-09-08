class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size(), n = grid[0].size(), enemy = 0, res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            enemy = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') dp[i][j] += enemy;
                else if (grid[i][j] == 'W') enemy = 0;
                else if (grid[i][j] == 'E') enemy++;
            }
            enemy = 0;
            for (int j = n-1; j >= 0; j--) {
                if (grid[i][j] == '0') dp[i][j] += enemy;
                else if (grid[i][j] == 'W') enemy = 0;
                else if (grid[i][j] == 'E') enemy++;
            }
        }

        for (int j = 0; j < n; j++) {
            enemy = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == '0') dp[i][j] += enemy;
                else if (grid[i][j] == 'W') enemy = 0;
                else if (grid[i][j] == 'E') enemy++;
            }
            enemy = 0;
            for (int i = m-1; i >= 0; i--) {
                if (grid[i][j] == 'W') enemy = 0;
                else if (grid[i][j] == 'E') enemy++;
                else if (grid[i][j] == '0') {
                    dp[i][j] += enemy;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};