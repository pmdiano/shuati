class Solution {
    int mm, nn;
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    inline int getIndex(int i, int j) {
        return i * nn + j;
    }

    inline bool inRange(int i, int j) {
        return (i >= 0) && (i < mm) && (j >= 0) && (j < nn);
    }

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (positions.empty()) {
            return vector<int>();
        }

        vector<int> ans(positions.size(), 0);
        if (m <= 0 || n <= 0) {
            return ans;
        }

        mm = m;
        nn = n;
        parent = vector<int>(m*n, -1);
        vector<vector<char>> board(m, vector<char>(n, 0));

        int count = 0;
        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};
        for (int i = 0; i < positions.size(); i++) {
            count++;
            int row = positions[i].first;
            int col = positions[i].second;
            board[row][col] = 1;
            parent[getIndex(row, col)] = getIndex(row, col);

            for (int t = 0; t < 4; t++) {
                int row2 = row + drow[t];
                int col2 = col + dcol[t];
                if (inRange(row2, col2) && board[row2][col2]) {
                    int px = find(getIndex(row, col));
                    int py = find(getIndex(row2, col2));
                    if (px != py) {
                        parent[py] = px;
                        count--;
                    }
                }
            }
            ans[i] = count;
        }

        return ans;
    }
};
