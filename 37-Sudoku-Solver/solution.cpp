class Solution {
    int rowFlags[9][10];
    int colFlags[9][10];
    int blockFlags[9][10];
    struct Pos {
        int r, c;
        Pos(int rr, int cc):r(rr), c(cc) {}
    };

    inline int getBlockNum(int r, int c) {
        int rr = r/3;
        int cc = c/3;
        return rr * 3 + cc;
    }

    void setAllFlags(int i, int j, int num, int f) {
        rowFlags[i][num] = f;
        colFlags[j][num] = f;
        blockFlags[getBlockNum(i, j)][num] = f;
    }

    bool isOk(int i, int j, int num) {
        return !rowFlags[i][num] && !colFlags[j][num] && !blockFlags[getBlockNum(i, j)][num];
    }

    bool dfs(vector<vector<char>>& board, vector<Pos>& blankPos, int n) {
        if (n < 0) {
            return true;
        }
        int r = blankPos[n].r;
        int c = blankPos[n].c;
        for (int num = 1; num <= 9; num++) {
            if (isOk(r, c, num)) {
                board[r][c] = '0' + num;
                setAllFlags(r, c, num, 1);
                if (dfs(board, blankPos, n-1)) {
                    return true;
                }
                setAllFlags(r, c, num, 0);
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rowFlags, 0, sizeof(rowFlags));
        memset(colFlags, 0, sizeof(colFlags));
        memset(blockFlags, 0, sizeof(blockFlags));

        vector<Pos> blankPos;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    blankPos.push_back(Pos(i, j));
                } else {
                    setAllFlags(i, j, board[i][j] - '0', 1);
                }
            }
        }

        (void)dfs(board, blankPos, blankPos.size() - 1);
    }
};