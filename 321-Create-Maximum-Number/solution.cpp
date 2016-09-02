class Solution {
    vector<int> findMaxKValue(vector<int>& nums, int k) {
        vector<int> res(k, 0);
        int i = 0, j = 0, n = nums.size();
        for (; i<n; i++) {
            while (j>0 && n-i>k-j && nums[i] > res[j-1]) --j;
            if (j<k) res[j++] = nums[i];
        }
        return res;
    }

    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        int m = v1.size();
        int n = v2.size();
        if (!m) return v2;
        if (!n) return v1;

        vector<int> res(m+n, 0);
        int i = 0, j = 0, k = 0;
        while (i < m || j < n) {
            res[k++] = compare(v1, i, v2, j) ? v1[i++] : v2[j++];
        }
        return res;
    }

    bool compare(vector<int>& v1, int i, vector<int>& v2, int j) {
        while (i < v1.size() && j < v2.size() && v1[i] == v2[j]) {
            ++i, ++j;
        }
        return j == v2.size() || (i < v1.size() && v1[i] > v2[j]);
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(k, 0);

        for (int i = max(0, k-n); i <= min(m, k); i++) {
            auto res1 = findMaxKValue(nums1, i);
            auto res2 = findMaxKValue(nums2, k-i);
            auto temp = merge(res1, res2);
            if (compare(temp, 0, res, 0)) res = temp;
        }

        return res;
    }
};