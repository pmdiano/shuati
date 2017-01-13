class NumMatrix {
    int row, col;
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix):row(0), col(0) {
        if (!matrix.empty() && !matrix[0].empty()) {
            row = matrix.size();
            col = matrix[0].size();
        }

        sum = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = max(0, row1);
        col1 = max(0, col1);
        row2 = min(row-1, row2);
        col2 = min(col-1, col2);
        return sum[row1][col1] + sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);