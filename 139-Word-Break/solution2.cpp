class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) {
            return false;
        }

        int n = s.size();
        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            f[i] = wordDict.count(s.substr(0, i+1));
            for (int j = 0; j < i; j++) {
                if (f[j] && wordDict.count(s.substr(j+1, i-j))) {
                    f[i] = 1;
                }
            }
        }

        return !!f[n-1];
    }
};
