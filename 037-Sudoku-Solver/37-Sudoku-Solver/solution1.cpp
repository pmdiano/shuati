class Solution {
    int rowFlags[9][10] = {{0}};
    int colFlags[9][10] = {{0}};
    int blkFlags[9][10] = {{0}};

    inline int blkIdx(int row, int col) {
        return (row / 3) * 3 + col / 3;
    }

    inline void setAllFlags(int row, int col, int num, int flag) {
        rowFlags[row][num] = flag;
        colFlags[col][num] = flag;
        blkFlags[blkIdx(row, col)][num] = flag;
    }

    inline bool okToSetNum(int row, int col, int num) {
        return !rowFlags[row][num] && !colFlags[col][num] && !blkFlags[blkIdx(row,col)][num];
    }

    bool dfs(vector<vector<char>>& board, vector<pair<int, int>> &emptyList, int pos) {
        if (pos == emptyList.size()) {
            return true;
        }

        int row = emptyList[pos].first, col = emptyList[pos].second;
        for (int num = 1; num <= 9; num++) {
            if (okToSetNum(row, col, num)) {
                board[row][col] = '0' + num;
                setAllFlags(row, col, num, 1);
                if (dfs(board, emptyList, pos+1)) {
                    return true;
                }
                setAllFlags(row, col, num, 0);
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> emptyList;
        for (int i = 0; i< board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    emptyList.push_back(make_pair(i, j));
                } else {
                    int num = board[i][j] - '0';
                    setAllFlags(i, j, num, 1);
                }
            }
        }
        dfs(board, emptyList, 0);
    }
};