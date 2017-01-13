class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        heights.push_back(-1);

        for (int i = 0; i < heights.size();) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i++);
            } else {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i-s.top()-1;
                ans = max(ans, w*h);
            }
        }

        return ans;
    }
};