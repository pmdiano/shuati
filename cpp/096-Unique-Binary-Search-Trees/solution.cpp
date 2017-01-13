class Solution {
    int helper(int n, vector<int>& mem) {
        if (n <= 1) {
            return 1;
        }

        if (mem[n]) {
            return mem[n];
        }

        int sum = 0;
        for (int root = 1; root <= n; root++) {
            sum += helper(root-1, mem) * helper(n-root, mem);
        }

        mem[n] = sum;
        return sum;
    }

public:
    int numTrees(int n) {
        if (n < 0) {
            return 0;
        }

        vector<int> mem(n+1, 0);
        return helper(n, mem);
    }
};