class Solution {
public:
    int bulbSwitch(int n) {
        return n > 0 ? (int)sqrt(n) : 0;
    }
};