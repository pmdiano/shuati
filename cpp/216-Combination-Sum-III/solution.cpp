class Solution {
    void dfs(int k, int n, int start, vector<int>& current, vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(current);
            return;
        }

        if (k == 0 || n < start) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            current.push_back(i);
            dfs(k-1, n-i, i+1, current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (k <= 0 || k > 9 || n < (k+k*k)/2 || n > (19*k-k*k)/2) {
            return ans;
        }

        vector<int> current;
        dfs(k, n, 1, current, ans);
        return ans;
    }
};