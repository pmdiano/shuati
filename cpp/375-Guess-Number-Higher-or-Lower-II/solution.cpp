class Solution {
    int helper(int m, int n, vector<vector<int>> &mem) {
        if (m >= n) {
            return 0;
        }
        if (mem[m][n]) {
            return mem[m][n];
        }

        int res = INT_MAX;
        for (int guess = m; guess <= n; guess++) {
            int cost = guess + max(helper(m, guess-1, mem), helper(guess+1, n, mem));
            if (cost < res) {
                res = cost;
            }
        }
        mem[m][n] = res;
        return res;
    }

public:
    int getMoneyAmount(int n) {
        vector<vector<int>> mem(n+1, vector<int>(n+1, 0));
        return helper(1, n, mem);
    }
};