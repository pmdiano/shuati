class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) {
            return false;
        }

        int hash[9];
        for (int i = 0; i < 9; i++) {
            memset(hash, 0, sizeof(hash));
            for (int j = 0; j < 9; j++) {
                if (!('1' <= board[i][j] && board[i][j] <= '9') && board[i][j] != '.') {
                    return false;
                }
                if (board[i][j] != '.' && hash[board[i][j]-'1']++) {
                    return false;
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            memset(hash, 0, sizeof(hash));
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.' && hash[board[i][j]-'1']++) {
                    return false;
                }
            }
        }

        for (int k = 0; k < 9; k++) {
            memset(hash, 0, sizeof(hash));
            int row = (k/3) * 3;
            int col = (k%3) * 3;
            for (int i = row; i < row+3; i++) {
                for (int j = col; j < col+3; j++) {
                    if (board[i][j] != '.' && hash[board[i][j]-'1']++) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};