class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }

        vector<int> f(n, 0);
        f[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            f[i] = f[i-1] + triangle[i][i];
            for (int j = i-1; j >= 1; j--) {
                f[j] = min(f[j], f[j-1]) + triangle[i][j];
            }
            f[0] = f[0] + triangle[i][0];
        }

        int ans = f[0];
        for (int j = 1; j < n; j++) {
            ans = min(ans, f[j]);
        }

        return ans;
    }
};