class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }

        nums.push_back(nums.back());
        int lower = nums[0], upper = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == upper + 1) {
                upper++;
            } else {
                if (lower == upper) {
                    result.push_back(to_string(lower));
                } else {
                    result.push_back(to_string(lower) + "->" + to_string(upper));
                }
                lower = upper = nums[i];
            }
        }

        nums.pop_back();
        return result;
    }
};