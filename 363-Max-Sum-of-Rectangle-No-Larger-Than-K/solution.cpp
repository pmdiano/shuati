class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int ans = numeric_limits<int>::min();

        for (int j = 0; j < n; j++) {
            vector<int> sum(m, 0);

            for (int l = j; l < n; l++) {
                for (int i = 0; i < m; i++) {
                    sum[i] += matrix[i][l];
                }

                set<int> mySet;
                mySet.insert(0);
                int currSum = 0;
                
                for (int a : sum) {
                    currSum += a;
                    // currSum - x <= k, x >= currSum - k
                    set<int>::iterator it = mySet.lower_bound(currSum - k);
                    if (it != mySet.end()) {
                        ans = max(ans, currSum - *it);
                    }
                    mySet.insert(currSum);
                }
            }
        }

        return ans;
    }
};