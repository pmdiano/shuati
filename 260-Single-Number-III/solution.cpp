class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        for (int x : nums) a ^= x;

        // Least significant bit, the two numbers must be
        // different on this bit
        int b = a & -a, c = 0;
        for (int x : nums) {
            if (x & b) {
                c ^= x;
            }
        }

        return vector<int>({c, c ^ a});
    }
};