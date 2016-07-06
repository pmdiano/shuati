class Solution {
    int largestRectangleArea(vector<int>& height) {
        int area = 0;
        stack<int> s;
        height.push_back(-1);

        for (int i = 0; i < height.size(); ) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int h = height[s.top()];
                s.pop();
                int w = s.empty() ? i : (i - s.top() - 1);
                area = max(area, w * h);
            }
        }

        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0) ? 1 : heights[i-1][j] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, largestRectangleArea(heights[i]));
        }

        return ans;
    }
};