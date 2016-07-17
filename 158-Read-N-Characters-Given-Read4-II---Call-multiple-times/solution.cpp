// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    int leftover = 0;
    char buf4[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0, once = 4, r4 = 4;

        if (leftover) {
            int use = min(leftover, n);
            memcpy(buf, buf4, use);
            total += use;
            leftover -= use;
            if (leftover) {
                for (int i = 0; i < leftover; i++) buf4[i] = buf4[i+use];
            }
        }

        while (total < n && once == 4) {
            r4 = read4(buf4);
            once = min(r4, n-total);
            memcpy(buf, buf4, once);
            total += once;
            buf += once;
        }

        if (once < r4) {
            leftover = r4 - once;
            for (int i = 0; i < leftover; i++) buf4[i] = buf4[i+once];
        }

        return total;
    }
};