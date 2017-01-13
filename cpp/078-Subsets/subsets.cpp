class Solution {
    void dfs(vector<int>& nums, int pos, vector<int>& current, vector<vector<int>>& result) {
        if (pos == nums.size()) {
            result.push_back(current);
            return;
        }
        
        dfs(nums, pos+1, current, result);
        current.push_back(nums[pos]);
        dfs(nums, pos+1, current, result);
        current.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> current;
        dfs(nums, 0, current, result);
        
        return result;
    }
};