class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size(), level = INT_MIN;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    q.push({heightMap[i][j], i*n+j});
                    visited[i][j] = 1;
                }
            }
        }

        int ans = 0;
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            int h = p.first, r = p.second / n, c = p.second % n;
            level = max(level, h);
            for (auto& dir : dirs) {
                int i = r + dir.first, j = c + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) {
                    if (heightMap[i][j] < level) ans += level - heightMap[i][j];
                    q.push({heightMap[i][j], i*n+j});
                    visited[i][j] = 1;
                }
            }
        }

        return ans;
    }
};
