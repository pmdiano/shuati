class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i+1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] < -nums[i]) {
                    j++;
                } else if (nums[j] + nums[k] > -nums[i]) {
                    k--;
                } else {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};
