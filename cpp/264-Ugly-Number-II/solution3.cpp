class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<int> res(n, 1);
        int i = 1, i2 = 0, i3 = 0, i5 = 0;
        while (i < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int m = min(m2, min(m3, m5));
            if (m2 == m) i2++;
            if (m3 == m) i3++;
            if (m5 == m) i5++;
            res[i++] = m;
        }

        return res[n-1];
    }
};
