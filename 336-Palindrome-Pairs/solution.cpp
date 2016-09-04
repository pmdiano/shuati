class Solution {
    bool isValid(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }

        for (int i = 0; i < words.size(); i++) {
            string t(words[i].rbegin(), words[i].rend());
            if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }

            int len = t.size();
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; it++) {
                int d = *it;
                if (isValid(t, 0, len-d-1) && m.count(t.substr(len-d))) {
                    res.push_back({i, m[t.substr(len-d)]});
                }
                if (isValid(t, d, len-1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }

        return res;
    }
};