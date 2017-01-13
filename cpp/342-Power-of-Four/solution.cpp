class Solution {
public:
    bool isPowerOfFour(int num) {// 0101 0101 0101 0101
        return !(num & (num-1)) && (num & 0x55555555);
    }
};