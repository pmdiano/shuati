class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return;
        }

        int n = nums.size();
        k = ((k % n) + n) % n;
        int m = n - k;
        int total = 0;

        for (int i = 0, total = 0; i < n && total < n; i++) {
            int temp = nums[i];
            int j = i, k = (j+m)%n;
            while (k != i) {
                nums[j] = nums[k];
                total++;
                j = k;
                k = (j+m) % n;
            }
            nums[j] = temp;
            total++;
        }
    }
};