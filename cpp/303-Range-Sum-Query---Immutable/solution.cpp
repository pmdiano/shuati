class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> &nums) : sum(nums.size(), 0) {
        if (nums.size()) {
            sum[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                sum[i] = sum[i-1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        j = min(j, (int)sum.size() - 1);
        i = max(i, 0);
        return i == 0 ? sum[j] : sum[j] - sum[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);