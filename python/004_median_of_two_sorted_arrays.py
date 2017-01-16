class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        if ((m+n) & 1):
            return self.kth(nums1, nums2, (m+n+1)/2)
        else:
            k1 = self.kth(nums1, nums2, (m+n)/2)
            k2 = self.kth(nums1, nums2, (m+n)/2 + 1)
            return (k1 + k2) / 2.0

    def kth(self, a, b, k):
        if len(a) > len(b):
            return self.kth(b, a, k)
        if not a:
            return b[k-1]
        if k == 1:
            return min(a[0], b[0])

        i = min(len(a), k/2)
        j = k - i
        if (a[i-1] == b[j-1]):
            return a[i-1]
        elif a[i-1] < b[j-1]:
            return self.kth(a[i:], b, k-i)
        else:
            return self.kth(a, b[j:], k-j)
