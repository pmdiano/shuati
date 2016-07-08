class Solution {
    void dfs(vector<int>& candidates, int target, int pos, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (candidates[pos] > target) {
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i-1]) {
                continue;
            }

            current.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;

        if (!candidates.empty()) {
            sort(candidates.begin(), candidates.end());
            dfs(candidates, target, 0, current, ans);
        }

        return ans;
    }
};