class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1; // 0
        for (int m = 1; m <= min(10, n); m++) {
            int num = 9, p = 9;
            for (int d = 2; d <= m; d++) {
                num *= p--;
            }
            res += num;
        }
        return res;
    }
};