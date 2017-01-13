class Solution {
    class compare {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            // first is num, second is frequency, min heap by frequency
            return rhs.second < lhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int x : nums) {
            hash[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            heap.push(*it);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        while (!heap.empty()) {
            res.push_back(heap.top().first);
            heap.pop();
        }

        return vector<int>(res.rbegin(), res.rend());
    }
};
