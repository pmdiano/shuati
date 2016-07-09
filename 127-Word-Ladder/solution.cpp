class Solution {
    void enqueueNeighbors(string word, queue<string>& q, unordered_set<string>& visited, unordered_set<string>& dict) {
        for (int i = 0; i < word.length(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (dict.find(word) != dict.end() && visited.find(word) == visited.end()) {
                    q.push(word);
                    visited.insert(word);
                }
            }
            word[i] = original;
        }
    }

public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int steps = 0;
        unordered_set<string> visited;
        queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);

        while (!q.empty()) {
            steps++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string top = q.front();
                q.pop();
                if (top == endWord) {
                    return steps;
                }
                enqueueNeighbors(top, q, visited, wordList);
            }
        }

        return 0;
    }
};