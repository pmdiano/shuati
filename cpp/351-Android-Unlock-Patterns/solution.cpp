class Solution {
    int dfs(int num, int len, vector<int> &visited) {
        if (len == 1) {
            return 1;
        }
        int res = 0;
        visited[num] = 1;
        for (int next = 0; next < 9; next++) {
            if (!visited[next] && isValid(visited, num, next)) {
                res += dfs(next, len-1, visited);
            }
        }
        visited[num] = 0;
        return res;
    }

    bool isValid(vector<int> &visited, int start, int end) {
        int mid = (start+end) / 2;
        if (mid+mid != start+end || visited[mid]) {
            return true;
        }

        if (start < 3 && end > 5 || start > 5 && end < 3) {
            return false;
        }
        int col1 = start % 3, col2 = end % 3;
        if (col1 == 0 && col2 == 2 || col1 == 2 && col2 == 0) {
            return false;
        }
        return true;
    }

public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<int> visited(9, 0);
        for (int len = m; len <= n; len++) {
            res += 4 * dfs(0, len, visited);
            res += 4 * dfs(1, len, visited);
            res += dfs(4, len, visited);
        }
        return res;
    }
};