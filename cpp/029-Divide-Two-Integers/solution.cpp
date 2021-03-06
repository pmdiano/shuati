class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }

        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long result = 0, shift = 31;
        while (shift >= 0) {
            if (a >= (b << shift)) {
                a -= (b << shift);
                result += (1LL << shift);
            }
            shift--;
        }

        result = (dividend ^ divisor) >> 31 ? -result : result;
        if (result > INT_MAX) {
            return INT_MAX;
        }
        return (int)result;
    }
};