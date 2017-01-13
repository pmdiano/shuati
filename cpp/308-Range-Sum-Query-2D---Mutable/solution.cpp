class NumMatrix {
    vector<vector<int>> mat;
    vector<vector<int>> bit;
    int M, N;

    void updateBIT(int row, int col, int val) {
        int diff = val - mat[row][col];
        mat[row][col] = val;
        row++, col++;

        for (int i = row; i <= M; i += i & (-i)) {
            for (int j = col; j <= N; j += j & (-j)) {
                bit[i][j] += diff;
            }
        }
    }

    int getSum(int row, int col) {
        int sum = 0;
        row++, col++;
        for (int i = row; i > 0; i -= i & (-i)) {
            for (int j = col; j > 0; j -= j & (-j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

public:
    NumMatrix(vector<vector<int>> &matrix) : M(0), N(0) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        M = matrix.size(), N = matrix[0].size();
        mat = vector<vector<int>>(M, vector<int>(N, 0));
        bit = vector<vector<int>>(M+1, vector<int>(N+1, 0));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                updateBIT(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        updateBIT(row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row1-1, col1-1) + getSum(row2, col2)
            - getSum(row1-1, col2) - getSum(row2, col1-1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);