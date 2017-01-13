class Solution {
    void find(string& low, string& high, string s, int& res) {
        if (s.length() >= low.length() && s.length() <= high.length()) {
            if (s.length() == low.length() && s < low || s.length() == high.length() && s > high) {
                return;
            }
            if (!(s.length() > 1 && s[0] == '0')) {
                res++;
            }
        }
        if (s.length() + 2 > high.length()) return;
        find(low, high, "0" + s + "0", res);
        find(low, high, "1" + s + "1", res);
        find(low, high, "6" + s + "9", res);
        find(low, high, "8" + s + "8", res);
        find(low, high, "9" + s + "6", res);
    }

public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        find(low, high, "", res);
        find(low, high, "0", res);
        find(low, high, "1", res);
        find(low, high, "8", res);
        return res;
    }
};