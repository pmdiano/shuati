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
        int total = 0, once = 4;
        while (total < n && once == 4) {
            int once = min(read4(buf), n-total);
            buf += once;
            total += once;
        }
        return total;
    }
};