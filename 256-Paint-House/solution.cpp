class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].size() != 3) {
            return 0;
        }

        int n = costs.size();
        vector<vector<int>> F(n+1, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                F[i+1][j] = min(F[i][(j+1)%3], F[i][(j+2)%3]) + costs[i][j];
            }
        }

        return min(F[n][0], min(F[n][1], F[n][2]));
    }
};