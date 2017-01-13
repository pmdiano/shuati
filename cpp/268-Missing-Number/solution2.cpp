class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = (long long)n * (n+1) / 2;
        for (int x : nums) {
            sum -= x;
        }
        return (int)sum;
    }
};