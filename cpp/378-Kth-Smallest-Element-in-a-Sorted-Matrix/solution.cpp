class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> heap;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                heap.push(matrix[i][j]);
                if (heap.size() > k) {
                    heap.pop();
                }
            }
        }
        return heap.top();
    }
};