/**
 * Given n distinct positive integers, integer k (k <= n) and a number target.
 * Find k numbers where sum is target. Calculate how many solutions there are?
 * 
 * Example
 * Given [1,2,3,4], k = 2, target = 5.
 * There are 2 solutions: [1,4] and [2,3].
 * Return 2.
 */
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum2(vector<int> A, int k, int target) {
      int n = A.size();

      // DP[i][j][t] means the total number of combinations that j numbers out of first A[0~i-1] sum up to t
      vector<vector<vector<int> > > DP(n+1, vector<vector<int> >(k+1, vector<int>(target+1, 0)));
      for (int i = 0; i <= A.size(); i++) {
        DP[i][0][0] = 1;
      }

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k,i); j++) {
          for (int t = 1; t < A[i-1]; t++) {
            DP[i][j][t] = DP[i-1][j][t];
          }
          for (int t = A[i-1]; t <= target; t++) {
            DP[i][j][t] = DP[i-1][j][t] + DP[i-1][j-1][t-A[i-1]];
          }
        }
      }

      return DP[n][k][target];
    }
    
    // Simplified version of above using "rolling array"
    int kSum(vector<int> A, int k, int target) {
        vector<vector<int> > DP(k+1, vector<int>(target+1, 0));
        DP[0][0] = 1;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = min(k, i+1); j >= 1; j--) {
                for (int t = A[i]; t <= target; t++) {
                    DP[j][t] += DP[j-1][t-A[i]];
                }
            }
        }
        
        return DP[k][target];
    }
};
