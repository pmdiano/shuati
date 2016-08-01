class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }
        int row = rooms.size(), col = rooms[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (auto dir : dirs) {
                int x = r + dir.first, y = c + dir.second;
                if (x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] <= rooms[r][c] + 1) continue;
                rooms[x][y] = rooms[r][c] + 1;
                q.emplace(x, y);
            }
        }
    }
};