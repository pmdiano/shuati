class Solution {
public:
    string toHex(int num) {
        char c[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string res;
        long n = num;
        if (n < 0) {
            n = -n;
            n ^= 0xFFFFFFFF;
            n += 1;
        }

        while (n) {
            res.insert(res.begin(), c[n%16]);
            n /= 16;
        }

        return res.size() ? res : "0";
    }
};