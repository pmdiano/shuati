class Solution {
    int m, n;
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    inline int getIndex(int i, int j) {
        return i * n + j;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        m = grid.size();
        n = grid[0].size();
        parent = vector<int>(m*n, 0);

        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent[getIndex(i, j)] = getIndex(i, j);
                    num++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (i < m-1 && grid[i+1][j] == '1') {
                    int px = find(getIndex(i, j));
                    int py = find(getIndex(i+1, j));
                    if (px != py) {
                        num--;
                        parent[py] = px;
                    }
                }
                if (j < n-1 && grid[i][j+1] == '1') {
                    int px = find(getIndex(i, j));
                    int py = find(getIndex(i, j+1));
                    if (px != py) {
                        num--;
                        parent[py] = px;
                    }
                }
            }
        }

        return num;
    }
};