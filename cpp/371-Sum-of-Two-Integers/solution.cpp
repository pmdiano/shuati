class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = a & b;

        if (carry) {
            return getSum(carry << 1, sum);
        } else {
            return sum;
        }
    }
};