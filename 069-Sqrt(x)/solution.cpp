class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }

        int lo = 1, hi = x;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int quo = x / mid;

            if (quo == mid) {
                return mid;
            } else if (quo < mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return (int)hi;
    }
};