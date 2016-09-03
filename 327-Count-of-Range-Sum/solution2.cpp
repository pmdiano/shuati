class Solution {
    int mergeAndCount(vector<long> &sums, int low, int high, int lower, int upper) {
        if (high - low <= 1) return 0;
        int mid = (low + high) / 2, m = mid, n = mid, count = 0;
        count += mergeAndCount(sums, low, mid, lower, upper);
        count += mergeAndCount(sums, mid, high, lower, upper);
        for (int i = low; i < mid; i++) {
            while (m < high && sums[m] - sums[i] < lower) m++;
            while (n < high && sums[n] - sums[i] <= upper) n++;
            count += n-m;
        }
        inplace_merge(sums.begin() + low, sums.begin() + mid, sums.begin() + high);
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> sums(len+1, 0);
        for (int i = 0; i < len; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
        return mergeAndCount(sums, 0, len+1, lower, upper);
    }
};
