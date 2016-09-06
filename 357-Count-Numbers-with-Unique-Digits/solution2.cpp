class Solution {
    int search(int prev, int max, int used) {
        int res = 0;
        if (prev < max) ++res;
        else return res;

        for (int i = 0; i < 10; i++) {
            if (!(used & (1 << i))) {
                used |= (1 << i);
                res += search(10*prev+i, max, used);
                used &= ~(1 << i);
            }
        }
        return res;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1, max = pow(10, n), used = 0;
        for (int i = 1; i < 10; i++) {
            used |= (1 << i);
            res += search(i, max, used);
            used &= ~(1 << i);
        }
        return res;
    }
};