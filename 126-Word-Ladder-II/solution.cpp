class Solution {
    void getPath(string startWord, unordered_map<string, vector<string>>& precursor, vector<vector<string>>& result, vector<string>& current) {
        if (current.back() == startWord) {
            vector<string> path = current;
            reverse(path.begin(), path.end());
            result.push_back(path);
            return;
        }

        vector<string>& next = precursor[current.back()];
        for (int i = 0; i < next.size(); i++) {
            current.push_back(next[i]);
            getPath(startWord, precursor, result, current);
            current.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> result;
        if (beginWord == endWord) {
            vector<string> path;
            path.push_back(beginWord);
            result.push_back(path);
            return result;
        }

        int n = beginWord.size();
        if (n == 0 || endWord.size() != beginWord.size()) {
            return result;
        }

        unordered_map<string, vector<string> > precursor;
        queue<string> Q;
        Q.push(beginWord);
        wordList.erase(beginWord);
        wordList.insert(endWord);

        bool found = false;
        while (!found && !Q.empty()) {
            int Qsize = Q.size();
            unordered_set<string> thisLayer;
            unordered_set<string> nextLayer;

            for (; Qsize; Qsize--) {
                string word = Q.front();
                Q.pop();
                thisLayer.insert(word);
            }

            for (unordered_set<string>::const_iterator it = thisLayer.begin(); it != thisLayer.end(); it++) {
                string word = *it;
                string prev = *it;
                if (word == endWord) {
                    found = true;
                    break;
                }
                
                for (int i = 0; i < n; i++) {
                    char oldChar = word[i];
                    for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                        if (newChar == oldChar) continue;
                        word[i] = newChar;
                        if (wordList.find(word) != wordList.end() && thisLayer.find(word) == thisLayer.end()) {
                            Q.push(word);
                            nextLayer.insert(word);
                            precursor[word].push_back(prev);
                        }
                    }
                    word[i] = oldChar;
                }
            }

            for (unordered_set<string>::const_iterator it = nextLayer.begin(); it != nextLayer.end(); it++) {
                wordList.erase(*it);
            }
        }

        if (found) {
            vector<string> current;
            current.push_back(endWord);
            getPath(beginWord, precursor, result, current);
        }

        return result;
    }
};