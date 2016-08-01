class Solution {
    int partition(vector<int>& nums, int p, int r) {
        int i = p-1;
        int x = nums[r];
        for (int j = p; j < r; j++) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[r]);
        return i;
    }

    // note this return index rather than value
    int quickSelect(vector<int>& nums, int p, int r, int k) {
        int q = partition(nums, p, r);
        if (k == q-p) {
            return q;
        } else if (k < q-p) {
            return quickSelect(nums, p, q-1, k);
        } else {
            return quickSelect(nums, q+1, r, k-(q-p+1));
        }
    }

public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }

        int p = quickSelect(nums, 0, n-1, (n+1)/2);
        swap(nums[p], nums[n-1]);
        partition(nums, 0, n-1);
        p = (n+1) / 2;

        // Note: this is not in-place
        vector<int> dup = nums;
        int i = 0, j = p, k = 0;
        while (i < p && j < n) {
            nums[k++] = dup[i++];
            nums[k++] = dup[j++];
        }
        if (i < p) {
            nums[k++] = dup[i++];
        }
    }
};