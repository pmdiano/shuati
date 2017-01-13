class Solution {
    void dfs(vector<int>& pos, int row, int& count) {
        if (row == pos.size()) {
            count++;
            return;
        }

        for (int col = 0; col < pos.size(); col++) {
            pos[row] = col;
            if (is_valid(pos, row)) {
                dfs(pos, row+1, count);
            }
        }
    }

    bool is_valid(vector<int>& pos, int row) {
        for (int i = 0; i < row; i++) {
            if (pos[i] == pos[row] || abs(i - row) == abs(pos[i] - pos[row])) {
                return false;
            }
        }

        return true;
    }

public:
    int totalNQueens(int n) {
        if (n <= 0) {
            return 0;
        }

        int count = 0;
        vector<int> pos(n, -1);
        dfs(pos, 0, count);

        return count;
    }
};