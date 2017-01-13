class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) {
            return 0;
        }

        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> F(n, vector<int>(k, 0));
        int last = -1, minCost = INT_MAX;

        for (int j = 0; j < k; j++) {
            F[0][j] = costs[0][j];
            if (F[0][j] < minCost) {
                minCost = F[0][j];
                last = j;
            }
        }

        for (int i = 1; i < n; i++) {
            int t = -1;
            minCost = F[i][last] = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (j != last) {
                    F[i][j] = F[i-1][last] + costs[i][j];
                    if (F[i][j] < minCost) {
                        minCost = F[i][j];
                        t = j;
                    }
                    F[i][last] = min(F[i][last], F[i-1][j] + costs[i][last]);
                }
            }
            if (F[i][last] < minCost) {
                minCost = F[i][last];
                t = last;
            }
            last = t;
        }

        minCost = INT_MAX;
        for (int j = 0; j < k; j++) {
            minCost = min(minCost, F[n-1][j]);
        }

        return minCost;
    }
};