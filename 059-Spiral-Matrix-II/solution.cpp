class Solution {
    int turns[4][2] = {
        {0, 1},     // go right
        {1, 0},     // go down
        {0, -1},    // go left
        {-1, 0}     // go up
    };

    void dfs(int num, int i, int j, int direction, vector<vector<int>>& matrix) {
        matrix[i][j] = num;
        for (int t = 0; t < 4; t++) {
            int d = (direction + t) % 4;
            int ti = i + turns[d][0];
            int tj = j + turns[d][1];
            if (0 <= ti && ti < matrix.size() && 0 <= tj && tj < matrix[0].size() && !matrix[ti][tj]) {
                dfs(num+1, ti, tj, d, matrix);
            }
        }
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> result(n, vector<int>(n, 0));
        dfs(1, 0, 0, 0, result);
        return result;
    }
};