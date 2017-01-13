class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return true;
        }

        unordered_map<int, vector<int>> hash;
        for (auto &p : points) {
            hash[p.second].push_back(p.first);
        }

        auto it = hash.begin();
        sort((*it).second.begin(), (*it).second.end());
        int mid = (*it).second.front() + (*it).second.back();

        for (; it != hash.end(); it++) {
            vector<int> &x = it->second;
            sort(x.begin(), x.end());
            int len = unique(x.begin(), x.end()) - x.begin();
            for (int i = 0, j = len-1; i <= j; i++, j--) {
                if (x[i] + x[j] != mid) {
                    return false;
                }
            }
        }

        return true;
    }
};