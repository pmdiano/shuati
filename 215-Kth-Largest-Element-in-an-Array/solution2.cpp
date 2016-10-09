class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k) return 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < k; i++) heap.push(nums[i]);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};