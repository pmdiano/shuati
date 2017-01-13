class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        x = negative ? -x : x;
        int y = 0;

        while (x) {
            int d = x % 10;
            int y2 = y * 10 + d;
            if ((y2 - d) / 10 != y) {
                // overflow
                return 0;
            }
            y = y2;
            x /= 10;
        }

        return negative ? -y : y;
    }
};