class Solution {
    void traverse(vector<vector<int>> &matrix, vector<vector<int>> &flag, queue<pair<int, int>> &q, const int mask) {
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int m = matrix.size(), n = matrix[0].size();
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (auto& dir : dirs) {
                int i = p.first + dir.first;
                int j = p.second + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n &&
                    matrix[i][j] >= matrix[p.first][p.second] && !(flag[i][j] & mask)) {
                    q.push(make_pair(i, j));
                    flag[i][j] |= mask;
                }
            }
        }
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }
        const int m = matrix.size(), n = matrix[0].size();
        const int pacific = 1, atlantic = 2;
        vector<vector<int>> flag(m, vector<int>(n, 0));

        queue<pair<int, int>> q1, q2;
        for (int i = 0; i < m; i++) {
            q1.push(make_pair(i, 0));
            q2.push(make_pair(i, n-1));
            flag[i][0] |= pacific;
            flag[i][n-1] |= atlantic;
        }
        for (int i = 0; i < n; i++) {
            q1.push(make_pair(0, i));
            q2.push(make_pair(m-1, i));
            flag[0][i] |= pacific;
            flag[m-1][i] |= atlantic;
        }
        traverse(matrix, flag, q1, pacific);
        traverse(matrix, flag, q2, atlantic);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //printf("flag[%d][%d]=%d\n", i, j, flag[i][j]);
                if ((flag[i][j] & pacific) && (flag[i][j] & atlantic)) {
                    ans.push_back(make_pair(i, j));
                }
            }
        }

        return ans;
    }
};