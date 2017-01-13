class Solution {
    // Status:
    // 0: dead -> dead
    // 1: live -> live
    // 2: live -> dead
    // 3: dead -> live
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        const static vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (auto& dir : dirs) {
                    int ii = i + dir.first, jj = j + dir.second;
                    if (ii < 0 || jj < 0 || ii == m || jj == n) continue;
                    if (board[ii][jj] == 1 || board[ii][jj] == 2) cnt++;
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                if (!board[i][j] && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] %= 2;
            }
        }
    }
};