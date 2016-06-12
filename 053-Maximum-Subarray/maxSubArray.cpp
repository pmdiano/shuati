class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};