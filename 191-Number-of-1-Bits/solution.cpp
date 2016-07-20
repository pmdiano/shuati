class Solution {
public:
    int hammingWeight(uint32_t n) {
        int w = 0;
        while (n) {
            w += (n & 1);
            n >>= 1;
        }
        return w;
    }
};