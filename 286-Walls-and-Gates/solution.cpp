class Solution {
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        static const int di[4] = {0, 0, 1, -1};
        static const int dj[4] = {1, -1, 0, 0};
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<char>> visited(m, vector<char>(n, 0));
        queue<pair<int, int>> q;

        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            for (int t = 0; t < 4; t++) {
                i = pos.first + di[t];
                j = pos.second + dj[t];
                if (0 <= i && i < m && 0 <= j && j < n && rooms[i][j] > 0 && !visited[i][j]) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    if (rooms[i][j] > rooms[pos.first][pos.second] + 1) {
                        rooms[i][j] = rooms[pos.first][pos.second] + 1;
                    }
                }
            }
        }
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }

        int m = rooms.size(), n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
};