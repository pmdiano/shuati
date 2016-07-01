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

        int i = min(m, k/2);
        int j = k - i;

        if (a[i-1] == b[j-1]) {
            return a[i-1];
        } else if (a[i-1] < b[j-1]) {
            return findKthSmallest(a+i, m-i, b, n, k-i);
        } else {
            return findKthSmallest(a, m, b+i, n-i, k-i);
        }
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
