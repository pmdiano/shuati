class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int i : nums) {
            heap.push(i);
        }

        if (heap.size() < k) {
            return 0;
        }

        for (int i = 0; i < k-1; i++) {
            heap.pop();
        }

        return heap.top();
    }
};