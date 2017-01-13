class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int maxSoFar = nums[0];
        int maxEnding, minEnding;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                maxEnding = max(nums[i], nums[i] * maxEndingHere);
                minEnding = min(nums[i], nums[i] * minEndingHere);
                
            } else {
                maxEnding = max(nums[i], nums[i] * minEndingHere);
                minEnding = min(nums[i], nums[i] * maxEndingHere);
            }
            
            maxEndingHere = maxEnding;
            minEndingHere = minEnding;
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};