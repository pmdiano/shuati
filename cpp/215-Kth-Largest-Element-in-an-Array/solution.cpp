class Solution {
    int partition(int* A, int p, int r) {
        int i = p-1;
        int x = A[r];

        for (int j = p; j < r; j++) {
            if (A[j] >= x) {
                i++;
                swap(A[i], A[j]);
            }
        }

        swap(A[i+1], A[r]);
        return i+1;
    }

    int quickSelect(int* A, int p, int r, int k) {
        int q = partition(A, p, r);
        if (q-p == k) {
            return A[q];
        } else if (q-p < k) {
            return quickSelect(A, q+1, r, k-(q-p+1));
        } else {
            return quickSelect(A, p, q-1, k);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size()) {
            return 0;
        }

        return quickSelect(&nums[0], 0, nums.size()-1, k-1);
    }
};