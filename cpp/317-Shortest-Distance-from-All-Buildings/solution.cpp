class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }
        const int m = grid.size(), n = grid[0].size();
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> total(m, vector<int>(n, 0));
        int canReach = 0, minDist = INT_MAX;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<vector<int>> dist(m, vector<int>(n, 0));
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (auto &dir : dirs) {
                            int newx = p.first + dir.first;
                            int newy = p.second + dir.second;
                            if (newx >= 0 && newx < m &&
                                newy >= 0 && newy < n &&
                                grid[newx][newy] == canReach) {
                                --grid[newx][newy];
                                dist[newx][newy] = dist[p.first][p.second] + 1;
                                total[newx][newy] += dist[newx][newy];
                                q.push(make_pair(newx, newy));
                            }
                        }
                    }
                    --canReach;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == canReach && total[i][j] < minDist) {
                    minDist = total[i][j];
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};