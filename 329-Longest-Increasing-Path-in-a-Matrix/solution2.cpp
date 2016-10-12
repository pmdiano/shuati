class Solution {
    struct Point {
        int x;
        int y;
        int h;
        Point() {}
        Point(int xx, int yy, int hh):x(xx), y(yy), h(hh) {}
    };

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<Point> points(m*n);
        for (int i = 0, k = 0; i < m; i++) {
            for (int j = 0; j < n; j++, k++) {
                points[k].x = i;
                points[k].y = j;
                points[k].h = matrix[i][j];
            }
        }

        sort(points.begin(), points.end(), [](const Point& lhs, const Point &rhs) {
            return lhs.h < rhs.h;
        });

        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (auto& p : points) {
            for (int i = 0; i < 4; i++) {
                int x2 = p.x + dx[i];
                int y2 = p.y + dy[i];
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && matrix[x2][y2] > matrix[p.x][p.y]) {
                    dp[x2][y2] = max(dp[x2][y2], dp[p.x][p.y] + 1);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};