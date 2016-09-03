class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int buffer[3];
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k == 0 || nums[i] > buffer[k-1]) {
                buffer[k++] = nums[i];
                if (k == 3) return true;
            } else {
                for (int j = 0; j < k; j++) {
                    if (buffer[j] >= nums[i]) {
                        buffer[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return false;
    }
};