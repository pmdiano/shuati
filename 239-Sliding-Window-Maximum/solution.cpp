class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() < k) {
            return vector<int>();
        }

        int n = nums.size();
        vector<int> ans(n-k+1, 0);
        deque<int> dq;

        int i = 0;
        for (; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (; i < n; i++) {
            ans[i-k] = nums[dq.front()];
            if (!dq.empty() && dq.front() == i-k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans[n-k] = nums[dq.front()];

        return ans;
    }
};