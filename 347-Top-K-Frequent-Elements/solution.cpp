class Solution {
    class compare {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            // first is number, second is frequency
            // we need a frequency min heap
            return lhs.second >= rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int n : nums) hash[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;
        auto it = hash.begin();
        for (int i = 0; i < k && it != hash.end(); i++, it++) {
            heap.push(make_pair(it->first, it->second));
        }
        for (; it != hash.end(); it++) {
            heap.push(make_pair(it->first, it->second));
            heap.pop();
        }

        vector<int> res;
        while (heap.size()) {
            res.push_back(heap.top().first);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};