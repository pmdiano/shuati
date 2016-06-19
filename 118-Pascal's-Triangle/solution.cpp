class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> pascal(numRows);

        for (int i = 0; i < numRows; i++) {
            pascal[i] = vector<int>(i+1, 1);
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }

        return pascal;
    }
};