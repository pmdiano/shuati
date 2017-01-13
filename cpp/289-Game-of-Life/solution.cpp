class Solution {
    int m, n;
    int neighbor_count(vector<vector<int>>& board, int i, int j) {
        const static vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        int cnt = 0;
        for (auto& dir : dirs) {
            int ii = i + dir.first, jj = j + dir.second;
            if (ii >= 0 && jj >= 0 && ii < m && jj < n && board[ii][jj]) {
                cnt++;
            }
        }
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size(), n = board[0].size();
        vector<vector<int>> next(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = neighbor_count(board, i, j);
                if (board[i][j] && cnt >= 2 && cnt <= 3) {
                    next[i][j] = 1;
                }
                if (!board[i][j] && cnt == 3) {
                    next[i][j] = 1;
                }
            }
        }
        board = next;
    }
};