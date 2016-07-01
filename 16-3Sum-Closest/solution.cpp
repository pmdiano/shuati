class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dif = numeric_limits<int>::max(), ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int j = i+1, k = nums.size() - 1;
            int localTarget = target - nums[i];

            while (j < k) {
                int sum = nums[j] + nums[k];
                if (abs(sum - localTarget) < dif) {
                    dif = abs(sum - localTarget);
                    ans = nums[i] + sum;
                }

                if (sum < localTarget) {
                    j++;
                } else if (sum > localTarget) {
                    k--;
                } else {
                    return ans;
                }
            }
        }

        return ans;
    }
};