class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0, mask_n = 1, mask_m = 1 << 31;
        while (mask_n) {
            if (n & mask_n) {
                m |= mask_m;
            }
            mask_n <<= 1;
            mask_m >>= 1;
        }
        return m;
    }
};