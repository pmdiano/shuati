class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) {
            return false;
        }

        int n = s.length();
        bool f[n];
        memset(f, 0, sizeof(bool)*n);

        for (int i = 0; i < n; i++) {
            f[i] = wordDict.find(s.substr(0, i+1)) != wordDict.end();
            for (int j = 0; j < i; j++) {
                if (f[j] && wordDict.find(s.substr(j+1, i-j)) != wordDict.end()) {
                    f[i] = true;
                }
            }
        }

        return f[n-1];
    }
};
