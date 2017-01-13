class Solution {
    template<class T1, class T2>
    class pair_comp {
    public:
        bool operator()(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
            return lhs.first + lhs.second < rhs.first + rhs.second;
        }
    };

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, pair_comp<int, int>> heap;
        for (int i1 = 0; i1 < min(k, (int)nums1.size()); i1++) {
            for (int i2 = 0; i2 < min(k, (int)nums2.size()); i2++) {
                if (heap.size() < k) {
                    heap.push(make_pair(nums1[i1], nums2[i2]));
                } else if (nums1[i1] + nums2[i2] < heap.top().first + heap.top().second) {
                    heap.pop();
                    heap.push(make_pair(nums1[i1], nums2[i2]));
                }
            }
        }

        int n = heap.size();
        vector<pair<int, int>> res(n);
        while (!heap.empty()) {
            res[--n] = heap.top();
            heap.pop();
        }
        return res;
    }
};