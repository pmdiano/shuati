class NumArray {
    vector<int> vec;
    vector<int> bit;

    int getSum(int i) {
        int sum = 0;
        i = i+1;

        while (i) {
            sum += bit[i];
            i -= (i & (-i));
        }

        return sum;
    }

    void updateBIT(int i, int val) {
        int diff = val - vec[i];
        vec[i] = val;
        i = i+1;

        while (i <= vec.size()) {
            bit[i] += diff;
            i += (i & (-i));
        }
    }

public:
    NumArray(vector<int> &nums): vec(nums.size(), 0), bit(nums.size()+1, 0) {
        for (int i = 0; i < nums.size(); i++) {
            updateBIT(i, nums[i]);
        }
    }

    void update(int i, int val) {
        if (i < 0 || i >= vec.size()) {
            return;
        }
        updateBIT(i, val);
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);