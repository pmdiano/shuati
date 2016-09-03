class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);

        for (int num : nums) {
            sum += num;
            count += distance(sums.lower_bound(sum-upper), sums.upper_bound(sum-lower));
            sums.insert(sum);
        }

        return count;
    }
};