class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }

        int water = 0, l = 0, r = height.size() - 1;
        int level = min(height[l], height[r]);
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] < level) {
                    water += (level - height[l]);
                } else {
                    level = min(height[l], height[r]);
                }
                l++;
            } else {
                if (height[r] < level) {
                    water += (level - height[r]);
                } else {
                    level = min(height[l], height[r]);
                }
                r--;
            }
        }

        return water;
    }
};