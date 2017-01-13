class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int x : nums) {
            two |= (one & x);
            one ^= x;
            int three = two & one;
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};