class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = m == 0 ? n : board[0].size();
        if (m <= 2 || n <= 2) return;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'Y';
                q.push(make_pair(i, 0));
            }
            if (board[i][n-1] == 'O') {
                board[i][n-1] = 'Y';
                q.push(make_pair(i, n-1));
            }
        }
        for (int j = 1; j < n-1; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'Y';
                q.push(make_pair(0, j));
            }
            if (board[m-1][j] == 'O') {
                board[m-1][j] = 'Y';
                q.push(make_pair(m-1, j));
            }
        }

        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (auto& dir : dirs) {
                int i = p.first + dir.first;
                int j = p.second + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O') {
                    board[i][j] = 'Y';
                    q.push(make_pair(i, j));
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};