class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp, res(nums.size(), 0);
        for (int i = (int)nums.size()-1; i >= 0; i--) {
            int left = 0, right = (int)tmp.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[i] <= tmp[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            res[i] = left;
            tmp.insert(tmp.begin() + left, nums[i]);
        }
        return res;
    }
};