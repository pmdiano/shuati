class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));

        f[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i = 1; i < m; i++) {
            f[i][0] = (obstacleGrid[i][0] == 0) ? f[i-1][0] : 0;
        }
        for (int j = 1; j < n; j++) {
            f[0][j] = (obstacleGrid[0][j] == 0) ? f[0][j-1] : 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = (obstacleGrid[i][j] == 0) ? f[i-1][j] + f[i][j-1] : 0;
            }
        }

        return f[m-1][n-1];
    }
};