class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }

        int num[256] = {0};
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;

        int ans = num[s[s.length() - 1]];
        for (int i = s.length() - 2; i >= 0; i--) {
            if (num[s[i]] < num[s[i+1]]) {
                ans -= num[s[i]];
            } else {
                ans += num[s[i]];
            }
        }

        return ans;
    }
};