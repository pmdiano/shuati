class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        const int ROW = matrix.size();
        const int COL = matrix[0].size();
        int row = ROW - 1;
        int col = 0;
        
        while (row >= 0 && col < COL) {
            if (target == matrix[row][col])
                return true;
            else if (target < matrix[row][col])
                --row;
            else
                ++col;
        }
        
        return false;
    }
};