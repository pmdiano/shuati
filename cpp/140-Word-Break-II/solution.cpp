class Solution {
    int getMaxLength(unordered_set<string>& wordDict) {
        int len = 0;
        for (const string& word : wordDict) {
            if (word.length() > len) {
                len = word.length();
            }
        }
        return len;
    }

    void helper(string& s, unordered_set<string>& wordDict, int maxLen, vector<vector<bool>>& f, int pos, string& current, vector<string>& result) {
        if (pos == f.size()) {
            result.push_back(current.substr(1));
            return;
        }

        int end = min(pos+maxLen, (int)f.size());
        for (int i = pos+1; i <= f.size(); i++) {
            string word = s.substr(pos, i-pos);
            if (wordDict.find(word) != wordDict.end() && (i == f.size() || f[i][f.size() - 1])) {
                current = current + " " + word;
                helper(s, wordDict, maxLen, f, i, current, result);
                current = current.substr(0, current.length() - word.length() - 1);
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.length() == 0) {
            return vector<string>();
        }

        int n = s.length();
        // f[i][j] means whether s[i..j] can be broken down to words in the dict
        vector<vector<bool>> f(n, vector<bool>(n, false));

        int maxLen = getMaxLength(wordDict);

        for (int i = 0; i < n; i++) {
            f[i][i] = wordDict.find(s.substr(i, 1)) != wordDict.end();
            for (int j = 1; j < n; j++) {
                f[i][j] = wordDict.find(s.substr(i, j-i+1)) != wordDict.end();
                for (int k = max(i, j-maxLen); k < j; k++) {
                    if (f[i][k] && wordDict.find(s.substr(k+1, j-k)) != wordDict.end()) {
                        f[i][j] = true;
                        break;
                    }
                }
            }
        }

        vector<string> result;
        string current;
        helper(s, wordDict, maxLen, f, 0, current, result);

        return result;
    }
};