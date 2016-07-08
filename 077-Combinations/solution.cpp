class Solution {
    void dfs(int n, int k, int pos, vector<int>& current, vector<vector<int>>& ans) {
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        if (n-pos+1 < k-current.size()) {
            return;
        }

        for (int i = pos; i <= n; i++) {
            current.push_back(i);
            dfs(n, k, i+1, current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> ans;

        if (n <= 0 || k <= 0 || k > n) {
            return ans;
        }

        dfs(n, k, 1, current, ans);
        return ans;
    }
};