class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = num / mid;
            if (mid == r && mid * r == num) {
                return true;
            } else if (mid <= r) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};