class Solution {
    vector<int> input;
public:
    Solution(vector<int> nums) {
        input = nums;
    }

    int pick(int target) {
        vector<int> v;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == target) {
                v.push_back(i);
            }
        }

        return v[rand() % (int)v.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */