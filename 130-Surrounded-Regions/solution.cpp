class Solution {
    int m, n;
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[py] = parent[px];
        }
    }

    void change(vector<vector<char>>& board, char from, char to) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == from) {
                    board[i][j] = to;
                }
            }
        }
    }

    inline int getIndex(int i, int j) {
        return i * n + j;
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        m = board.size();
        n = board[0].size();
        parent = vector<int>(m*n, -1);
        vector<pair<int, int>> boundary;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    parent[getIndex(i, j)] = getIndex(i, j);
                    if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                        boundary.push_back(make_pair(i, j));
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                if (i < m-1 && board[i+1][j] == 'O') {
                    merge(getIndex(i, j), getIndex(i+1, j));
                }
                if (j < n-1 && board[i][j+1] == 'O') {
                    merge(getIndex(i, j), getIndex(i, j+1));
                }
            }
        }

        unordered_set<int> hash;
        for (auto pair : boundary) {
            hash.insert(find(getIndex(pair.first, pair.second)));
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                int p = find(getIndex(i, j));
                // Connected to boundary, so mark it differently
                if (hash.find(p) != hash.end()) {
                    board[i][j] = 'Y';
                }
            }
        }

        change(board, 'O', 'X');
        change(board, 'Y', 'O');
    }
};