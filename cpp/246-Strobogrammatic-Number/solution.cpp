class Solution {
public:
    bool isStrobogrammatic(string num) {
        static const int mapping[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        for (int i = 0, j = num.length() - 1; i <= j; i++, j--) {
            if (mapping[num[i] - '0'] != num[j] - '0') return false;
        }
        return true;
    }
};