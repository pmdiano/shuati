class Solution {
    int helper(long n) {
        if (n <= 0) return 0;
        if (n == 1) return 0;
        if (n % 2 == 0) {
            int steps = 0;
            while (n % 2 == 0) {
                n = n / 2;
                steps++;
            }
            return helper(n) + steps;
        }
        return min(helper(n+1), helper(n-1)) + 1;
    }
public:
    int integerReplacement(int n) {
        return helper(long(n));
    }
};