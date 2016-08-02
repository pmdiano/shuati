class Solution {
public:
    bool isPowerOfThree(int n) {
        static int M3 = pow(3.0, int(log((double)0x7FFFFFFF)/log(3.0)));
        return n > 0 && M3 % n == 0;
    }
};