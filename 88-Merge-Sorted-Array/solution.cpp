class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy = nums1;
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1Copy[i] < nums2[j]) {
                nums1[k++] = nums1Copy[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }

        while (i < m) {
            nums1[k++] = nums1Copy[i++];
        }
        while (j < n) {
            nums1[k++] = nums2[j++];
        }
    }
};