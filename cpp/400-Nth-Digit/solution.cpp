class Solution {
public:
    int findNthDigit(int n) {
        n--;
        int d = 1;
        long numd = 9;
        while (n >= d * numd) {
            n -= d * numd;
            d++;
            numd *= 10;
        }

        long base = pow(10, d-1);
        long num = base + n/d;
        n = n % d;
        int shift = d-1-n;
        while (shift) {
            num /= 10;
            shift--;
        }

        return num % 10;
    }
};