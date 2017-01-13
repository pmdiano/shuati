class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
            if (lhs.first == rhs.first)
                return lhs.second > rhs.second;
            return lhs.first < rhs.first;
        });

        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) {
                dp.push_back(envelopes[i].second);
            } else {
                *it = envelopes[i].second;
            }
        }

        return dp.size();
    }
};