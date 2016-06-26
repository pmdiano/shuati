/**
 * Given an integer array, adjust each integers so that the difference of every adjacent integers
 * are not greater than a given number target. If the array before adjustment is A, the array
 * after adjustment is B, you should minimize the sum of |A[i]-B[i]|
 * 
 * Notice
 * You can assume each number in the array is a positive integer and not greater than 100.
 *
 * Example
 * Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and
 * it's minimal. Return 2.
 */

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        if (A.empty()) {
            return 0;
        }

        const int n = A.size();
        const int m = 100;
        vector<vector<int>> F(n, vector<int>(m+1, numeric_limits<int>::max()));

        for (int j = 0; j <= m; j++) {
            F[0][j] = abs(A[0] - j);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                int lastStart = max(0, j-target);
                int lastEnd = min(m, j+target);
                for (int k = lastStart; k <= lastEnd; k++) {
                    F[i][j] = min(F[i][j], F[i-1][k] + abs(A[i] - j));
                }
            }
        }

        int ans = F[n-1][0];
        for (int j = 1; j <= m; j++) {
            ans = min(ans, F[n-1][j]);
        }

        return ans;
    }
};
