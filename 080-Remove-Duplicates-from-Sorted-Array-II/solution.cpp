class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = min(2, (int)nums.size());

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[len-1] || nums[i] != nums[len-2]) {
                nums[len++] = nums[i];
            }
        }

        return len;
    }
};
