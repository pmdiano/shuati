class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m*n - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (target == matrix[mid/n][mid%n])
                return true;
            else if (target < matrix[mid/n][mid%n])
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return false;
    }
};