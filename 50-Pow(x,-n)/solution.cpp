class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) {
            return 0.0;
        }

        if (n == INT_MIN) {
            return myPow(x, n+1) / x;
        }

        bool negative = n < 0;
        n = n < 0 ? -n : n;
        double ans = 1.0;
        while (n) {
            if (n & 1) ans = ans * x;
            n >>= 1;
            x = x * x;
        }
        return negative ? 1.0 / ans : ans;
    }
};