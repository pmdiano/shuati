class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        vector<string> p;
        p.push_back(beginWord);
        queue<vector<string>> q;
        q.push(p);

        wordList.insert(endWord);
        set<string> dict;
        int level = 1, minLevel = INT_MAX;

        while (!q.empty()) {
            auto path = q.front(); q.pop();
            if (path.size() > level) {
                for (auto word : dict) {
                    wordList.erase(word);
                }
                dict.clear();
                level = path.size();
                if (level > minLevel) break;
            }

            string last = path.back();
            for (int i = 0; i < last.size(); i++) {
                string newLast = last;
                for (char c = 'a'; c <= 'z'; c++) {
                    newLast[i] = c;
                    if (newLast != last && wordList.find(newLast) != wordList.end()) {
                        dict.insert(newLast);
                        vector<string> newPath = path;
                        newPath.push_back(newLast);
                        if (newLast == endWord) {
                            res.push_back(newPath);
                            minLevel = level;
                        } else {
                            q.push(newPath);
                        }
                    }
                }
            }
        }

        return res;
    }
};