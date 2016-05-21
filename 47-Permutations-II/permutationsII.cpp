class Solution {
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        int lasti = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (lasti >= 0 && nums[i] == nums[lasti]) continue;
            
            lasti = i;
            used[i] = true;
            current.push_back(nums[i]);
            dfs(nums, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        dfs(nums, used, current, result);
        
        return result;
    }
};