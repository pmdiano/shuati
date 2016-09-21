class Solution {
    void dfs(int parent, int n, vector<int>& res) {
        if (parent > n) {
            return;
        }

        res.push_back(parent);
        for (int i = 0; i <= 9; i++) {
            dfs(10*parent+i, n, res);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, res);
        }
        return res;
    }
};