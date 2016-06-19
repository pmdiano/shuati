class Solution {
public:
    int numTrees(int n) {
        if (n < 0) {
            return 0;
        }

        int f[n+1];
        memset(f, 0, sizeof(int)*(n+1));
        f[0] = 1;
        f[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                f[i] += f[j] * f[i-j-1];
            }
        }

        return f[n];
    }
};