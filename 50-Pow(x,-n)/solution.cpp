class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        if (x == 0.0) {
            return 0.0;
        }

        if (n == INT_MIN) {
            return myPow(x, n+1) / x;
        }

        if (n < 0) {
            x = 1/x;
            n = -n;
        }

        double ans = 1.0;
        while (n) {
            if (n & 1) ans = ans * x;
            n >>= 1;
            x = x * x;
        }
        return ans;
    }
};