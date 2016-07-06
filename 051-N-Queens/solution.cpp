class Solution {
    void dfs(int row, vector<int>& pos, vector<vector<string>>& result) {
        // pos[i] means which column queen is placed at row i
        if (row == pos.size()) {
            result.push_back(print_queen(pos));
            return;
        }

        for (int col = 0; col < pos.size(); col++) {
            pos[row] = col;
            if (is_valid(row, pos)) {
                dfs(row+1, pos, result);
            }
        }
    }

    vector<string> print_queen(vector<int>& pos) {
        vector<string> result(pos.size(), string(pos.size(), '.'));
        for (int i = 0; i < pos.size(); i++) {
            result[i][pos[i]] = 'Q';
        }
        return result;
    }

    bool is_valid(int row, vector<int>& pos) {
        for (int i = 0; i < row; i++) {
            if (pos[row] == pos[i] || abs(row - i) == abs(pos[row] - pos[i])) {
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n <= 0) {
            return result;
        }

        vector<int> pos(n, -1);
        dfs(0, pos, result);
        return result;
    }
};