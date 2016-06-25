class Solution {
    bool isValidOneDigit(const char a) {
        return a >= '1' && a <= '9';
    }
    bool isValidTwoDigits(const char a, const char b) {
        return (a == '1') || (a == '2' && b <= '6');
    }

public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        int n = s.length();
        int f[n+1];
        f[0] = 1;
        f[1] = 1;
        if (!isValidOneDigit(s[0])) {
            return 0;
        }

        for (int i = 2; i <= n; i++) {
            // current: s[i-1]; previous: s[i-2]
            bool oneOK = isValidOneDigit(s[i-1]);
            bool twoOK = isValidTwoDigits(s[i-2], s[i-1]);

            if (oneOK) {
                if (twoOK) {
                    f[i] = f[i-1] + f[i-2];
                } else {
                    f[i] = f[i-1];
                }
            } else {
                if (twoOK) {
                    f[i] = f[i-2];
                } else {
                    return 0;
                }
            }
        }

        return f[n];
    }
};
