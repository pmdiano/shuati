class Solution {
    // Find first element greater than or equal to target
    int binarySearch(vector<int>& nums, double target) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) {
            return vector<int>();
        }

        vector<int> ans(nums.size());
        if (a == 0) {
            for (int i = 0; i < nums.size(); i++) {
                ans[i] = b * nums[i] + c;
            }
            if (b < 0) {
                reverse(ans.begin(), ans.end());
            }
            return ans;
        }

        vector<int> computed(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            computed[i] = a*nums[i]*nums[i] + b*nums[i] + c;
        }

        double mid = (double)(-b) / (2*a);
        int p = binarySearch(nums, mid);
        int q = p-1;
        int i = 0;

        while (q >= 0 && p < nums.size()) {
            if (a > 0) {
                if (computed[q] < computed[p]) {
                    ans[i++] = computed[q--];
                } else {
                    ans[i++] = computed[p++];
                }
            } else {
                if (computed[q] > computed[p]) {
                    ans[i++] = computed[q--];
                } else {
                    ans[i++] = computed[p++];
                }
            }
        }
        while (q >= 0) {
            ans[i++] = computed[q--];
        }
        while (p < nums.size()) {
            ans[i++] = computed[p++];
        }
        

        if (a < 0) {
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};
