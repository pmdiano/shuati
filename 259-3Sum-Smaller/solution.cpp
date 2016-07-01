class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int localTarget = target - nums[i];
            int j = i+1, k = nums.size()-1;

            while (j < k) {
                if (nums[j] + nums[k] < localTarget) {
                    ans += k-j;
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }
};
