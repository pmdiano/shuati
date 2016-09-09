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
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                heap.push(make_pair(n1, n2));
                if (heap.size() > k) {
                    heap.pop();
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