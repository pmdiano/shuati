class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }

        int m = matrix.size(), n = matrix[0].size();
        int i1 = 0, j1 = 0;         // top left
        int i2 = m-1, j2 = n-1;     // bottom right
        int i = 0, j = 0, k = 0;
        vector<int> ans(m*n, 0);

        while (i1 < i2 && j1 < j2) {
            for (j = j1; j <= j2; j++) ans[k++] = matrix[i1][j];    // top
            for (i = i1+1; i < i2; i++) ans[k++] = matrix[i][j2];   // right
            for (j = j2; j >= j1; j--) ans[k++] = matrix[i2][j];    // bottom
            for (i = i2-1; i > i1; i--) ans[k++] = matrix[i][j1];   // left
            i1++, j1++;
            i2--, j2--;
        }

        if (i1 <= i2 && j1 == j2) {
            for (i = i1; i <= i2; i++) ans[k++] = matrix[i][j1];
        }

        if (j1 < j2 && i1 == i2) {
            for (j = j1; j <= j2; j++) ans[k++] = matrix[i1][j];
        }

        return ans;
    }
};