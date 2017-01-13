class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;

        int m = n, d = 1;
        while (m >= 10) {
            m /= 10;
            d *= 10;
        }

        int count = 0, dd = 1;
        while (dd != d) {
            int c = n / (10 * dd);
            int r = n - c * 10 * dd;
            count += c * dd;
            if (r >= 2 * dd - 1) count += dd;
            else if (r >= dd - 1) count += (r - dd + 1);
            dd *= 10;
        }

        // can't fit this into above loop because of potential overflow
        if (n / dd >= 2) {
            count += dd;
        } else {
            count += (n - (dd - 1));
        }

        // 3178, dd = 1,    c = 317, r = 8
        // 3178, dd = 10,   c = 31,  r = 78
        // 3178, dd = 100,  c = 3,   r = 178
        // 3178, dd = 1000, count += 1000

        return count;
    }
};