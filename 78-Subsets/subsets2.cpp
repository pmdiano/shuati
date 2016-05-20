class Solution {
    void dfs(vector<int>& nums, int pos, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for (int i = pos; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            dfs(nums, i+1, current, result);
            current.pop_back();
        }
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