class Solution {
    int findKthSmallest(int* a, int m, int *b, int n, int k) {
        if (m > n) {
            return findKthSmallest(b, n, a, m, k);
        }
        if (m == 0) {
            return b[k-1];
        }
        if (k == 1) {
            return min(a[0], b[0]);
        }

        int d = min(m, k/2);
        if (a[d-1] < b[d-1]) {
            return findKthSmallest(a+d, m-d, b, n, k-d);
        }
        if (b[d-1] < a[d-1]) {
            return findKthSmallest(a, m, b+d, n-d, k-d);
        }
        if (2*d == k) {
            return a[d-1];
        }
        if (2*d == k-1) {
            return findKthSmallest(a+d, m-d, b+d, n-d, 1);
        }
        return findKthSmallest(a+m, 0, b+m, n-m, k-2*m);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if ((m+n) & 1) {
            return (double)findKthSmallest(&nums1[0], nums1.size(), &nums2[0], nums2.size(), (m+n+1)/2);
        } else {
            return (double)(findKthSmallest(&nums1[0], nums1.size(), &nums2[0], nums2.size(), (m+n)/2)
                          + findKthSmallest(&nums1[0], nums1.size(), &nums2[0], nums2.size(), (m+n)/2+1))/2.0;
        }
    }
};
