class Solution {
    int less_or_equal(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m-1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] > target) {
                i--;
            } else {
                res += i+1;
                j++;
            }
        }
        return res;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int low = matrix[0][0], high = matrix[m-1][n-1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = less_or_equal(matrix, mid);
            if (count < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};