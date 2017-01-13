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

    string getStringFromPath(const string &s, const vector<int>& path) {
        string str;
        int i = 0;
        for (int j : path) {
            str += " " + s.substr(i, j-i+1);
            i = j+1;
        }
        return str.substr(1);
    }

    // Note we don't need the dictionary here
    void search(string &s, int pos, vector<vector<bool>>& isWord, vector<bool>& possible, vector<int>& path, vector<string>& result) {
        if (pos == s.length()) {
            result.push_back(getStringFromPath(s, path));
            return;
        }

        for (int i = pos; i < s.length(); i++) {
            if (isWord[pos][i] && possible[i+1]) {
                path.push_back(i);
                search(s, i+1, isWord, possible, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.length() == 0) {
            return vector<string>();
        }

        int maxLen = getMaxLength(wordDict);
        int n = s.length();
        vector<vector<bool>> isWord(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < min(i+maxLen, n); j++) {
                if (wordDict.find(s.substr(i, j-i+1)) != wordDict.end()) {
                    isWord[i][j] = true;
                }
            }
        }

        // possible[i] means s[i..end] can be broken down
        vector<bool> possible(n+1, false);
        possible[n] = true;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < min(i+maxLen, n); j++) {
                if (isWord[i][j] && possible[j+1]) {
                    possible[i] = true;
                    break;
                }
            }
        }

        vector<string> result;
        vector<int> path;
        search(s, 0, isWord, possible, path, result);

        return result;
    }
};