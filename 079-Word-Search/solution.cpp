class Solution {
    const int drow[4] = {-1, 1, 0, 0};
    const int dcol[4] = {0, 0, -1, 1};

    int m, n;
    inline bool inRange(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    bool search(vector<vector<char>>& board, vector<vector<int>>& flag, int i, int j, string& word, int pos) {
        if (pos == word.length()) {
            return true;
        }

        if (!inRange(i, j) || flag[i][j] || word[pos] != board[i][j]) {
            return false;
        }

        flag[i][j] = 1;
        for (int t = 0; t < 4; t++) {
            if (search(board, flag, i+drow[t], j+dcol[t], word, pos+1)) {
                return true;
            }
        }
        flag[i][j] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }

        m = board.size();
        n = board[0].size();
        if (m*n < word.length()) {
            return false;
        }

        vector<vector<int>> flag(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, flag, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};