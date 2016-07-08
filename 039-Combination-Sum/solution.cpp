class Solution {
    void dfs(vector<int>& candidates, int pos, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (candidates[pos] > target) {
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            dfs(candidates, i, target-candidates[i], current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());

        dfs(candidates, 0, target, current, ans);
        return ans;
    }
};