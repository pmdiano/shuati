class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        long long F = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            F += A[i] * i;
            sum += A[i];
        }

        long long ans = F;
        for (int r = 1; r < n; r++) {
            F += (sum - n * A[n-r]);
            ans = max(ans, F);
        }
        return ans;
    }
};