class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n == 0) {
            return 0;
        }

        int w = 1;
        while (n & (n-1)) {
            n &= (n-1);
            w++;
        }
        return w;
    }
};
