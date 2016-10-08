// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char cache[4];
    int start = 0;
    int end = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int idx = 0, remain = n;
        while (remain) {
            if (start != end) {
                buf[idx++] = cache[start++];
                remain--;
            } else {
                start = 0;
                if ((end = read4(cache)) == 0) {
                    return idx;
                }
            }
        }
        return idx;
    }
};