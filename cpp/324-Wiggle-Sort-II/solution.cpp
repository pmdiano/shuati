class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int j = (n+1) / 2, k = n;
        for (int i = 0; i < n; i++) {
            nums[i] = i & 1 ? temp[--k] : temp[--j];
        }
    }
};