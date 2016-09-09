class Solution {
    int myPow(int a, int n) {
        int res = 1;
        while (n) {
            if (n & 1) res = (res * a) % 1337;
            a = (a * a) % 1337;
            n >>= 1;
        }
        return res % 1337;
    }

public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        a %= 1337;
        for (int i = 0; i < b.size(); i++) {
            res = myPow(res, 10) * myPow(a, b[i]) % 1337;
        }
        return res;
    }
};