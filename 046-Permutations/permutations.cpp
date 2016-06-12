class Solution {
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            
            current.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, current, result);
            used[i] = false;
            current.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        
        dfs(nums, used, current, result);
        
        return result;
    }
};