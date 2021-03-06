class TicTacToe {
    vector<int> rows, cols;
    int diag, rdiag, N;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : rows(n, 0), cols(n, 0), diag(0), rdiag(0), N(n) {
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int inc = player == 1 ? 1 : -1;
        rows[row] += inc;
        cols[col] += inc;
        if (row == col) diag += inc;
        if (row + col == N - 1) rdiag += inc;

        if (rows[row] == N || rows[row] == -N ||
            cols[col] == N || cols[col] == -N ||
            diag == N || diag == -N || rdiag == N || rdiag == -N)
            return player;

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */