class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }

        int res = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            int level = min(height[left], height[right]);
            if (height[left] == level) {
                ++left;
                while (left < right && height[left] < level) {
                    res += level - height[left];
                    ++left;
                }
            } else {
                --right;
                while (left < right && height[right] < level) {
                    res += level - height[right];
                    --right;
                }
            }
        }
        
        return res;
    }
};