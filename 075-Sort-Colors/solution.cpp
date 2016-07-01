class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                nums[i] = 2;
                nums[white++] = 1;
            } else if (nums[i] == 0) {
                nums[i] = 2;
                nums[white++] = 1;
                nums[red++] = 0;
            }
        }
    }
};