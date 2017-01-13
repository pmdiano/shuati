class Solution {
    int getBlockNum(int r, int c) {
        r /= 3, c /= 3;
        return 3*r+c;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) {
            return false;
        }
        vector<vector<int>> rowFlags(9, vector<int>(9, 0));
        vector<vector<int>> colFlags(9, vector<int>(9, 0));
        vector<vector<int>> blockFlags(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if ('1' <= board[i][j] && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlags[i][c] || colFlags[j][c] || blockFlags[getBlockNum(i,j)][c])
                        return false;
                    rowFlags[i][c] = 1;
                    colFlags[j][c] = 1;
                    blockFlags[getBlockNum(i,j)][c] = 1;
                }
            }
        }
        return true;
    }
};