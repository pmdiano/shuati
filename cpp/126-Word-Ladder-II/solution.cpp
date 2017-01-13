class Solution {
    void dfs(string beginWord, int steps, unordered_map<string, unordered_set<string>>& precursor, vector<string>& path, vector<vector<string>>& ans) {
        if (path.back() == beginWord) {
            vector<string> path2 = path;
            reverse(path2.begin(), path2.end());
            ans.push_back(path2);
            return;
        }

        if (path.size() == steps) {
            return;
        }

        string word = path.back();
        for (string prev : precursor[word]) {
            path.push_back(prev);
            dfs(beginWord, steps, precursor, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> ans;
        if (beginWord == endWord) {
            vector<string> path;
            path.push_back(beginWord);
            ans.push_back(path);
            return ans;
        }

        if (beginWord.length() != endWord.length()) {
            return ans;
        }

        unordered_map<string, unordered_set<string>> precursor;
        queue<string> q;
        int steps = 0;
        bool found = false;

        q.push(beginWord);
        wordList.erase(beginWord);
        wordList.insert(endWord);

        while (!q.empty() && !found) {
            steps++;
            unordered_set<string> thisLayer;
            unordered_set<string> nextLayer;

            int n = q.size();
            for (int i = 0; i < n; i++) {
                thisLayer.insert(q.front());
                q.pop();
            }

            for (string word : thisLayer) {
                if (word == endWord) {
                    found = true;
                    break;
                    // OK to break here, since we already got all precursors of endWord in previous rounds
                }

                string next = word;
                for (int i = 0; i < next.size(); i++) {
                    char original = next[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        next[i] = c;
                        if (wordList.find(next) != wordList.end()) {
                            q.push(next);
                            nextLayer.insert(next);
                            precursor[next].insert(word);   // Key of this problem
                        }
                    }
                    next[i] = original;
                }
            }

            for (string word : nextLayer) {
                wordList.erase(word);
            }
        }

        if (found) {
            vector<string> path;
            path.push_back(endWord);
            dfs(beginWord, steps, precursor, path, ans);
        }

        return ans;
    }
};
