// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buf2[4];
        int total = 0, once = 4;
        while (total < n && once == 4) {
            if (n-total >= 4) {
                once = read4(buf);
            } else {
                once = min(read4(buf2), n-total);
                memcpy(buf, buf2, once);
            }
            buf += once;
            total += once;
        }
        return total;
    }
};