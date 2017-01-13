class Solution {
    void dfs(int n, int start, vector<int>& current, vector<vector<int>>& ans) {
        for (int i = start; i <= (int)sqrt(n); i++) {
            if (n % i != 0) {
                continue;
            }

            current.push_back(i);
            current.push_back(n/i);
            ans.push_back(current);

            current.pop_back();
            dfs(n/i, i, current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> current;
        if (n <= 1) {
            return ans;
        }

        dfs(n, 2, current, ans);
        return ans;
    }
};