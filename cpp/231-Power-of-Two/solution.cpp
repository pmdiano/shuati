class Solution {
public:
    bool isPowerOfTwo(int n) {
        int a = n & (n-1);
        return n > 0 && !a;
    }
};