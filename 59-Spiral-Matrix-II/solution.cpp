class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1, i1 = 0, j1 = 0, i2 = n-1, j2 = n-1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        while (i1 < i2 && j1 < j2) {
            for (int j = j1; j <= j2; j++) matrix[i1][j] = val++;
            for (int i = i1+1; i < i2; i++) matrix[i][j2] = val++;
            for (int j = j2; j >= j1; j--) matrix[i2][j] = val++;
            for (int i = i2-1; i > i1; i--) matrix[i][j1] = val++;
            i1++, j1++, i2--, j2--;
        }
        if (i1 == i2) {
            matrix[i1][j1] = val;
        }
        return matrix;
    }
};