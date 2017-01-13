class Solution {
    class Trie {
        class TrieNode {
            friend class Trie;
            int R;
            vector<TrieNode*> next;
            bool hasWord;
        public:
            TrieNode() : R(26), next(26, nullptr), hasWord(false) {
            }
            
            void addWord(string &word, int d) {
                if (d == word.length()) {
                    hasWord = true;
                    return;
                }

                char c = word[d];
                if (next[c-'a'] == nullptr) {
                    next[c-'a'] = new TrieNode();
                }
                next[c-'a']->addWord(word, d+1);
            }
            
            TrieNode *get(string &word, int d) {
                if (d == word.length()) {
                    return this;
                }
                
                char c = word[d];
                if (next[c-'a'] == nullptr) {
                    return nullptr;
                }
                return next[c-'a']->get(word, d+1);
            }
            
            TrieNode *remove(string &word, int d) {
                if (d == word.length()) {
                    hasWord = false;
                } else {
                    char c = word[d];
                    next[c-'a'] = next[c-'a']->remove(word, d+1);
                }
                
                if (hasWord) {
                    return this;
                }
                
                for (int i = 0; i < R; ++i) {
                    if (next[i]) {
                        return this;
                    }
                }
                
                delete this;
                return nullptr;
            }
        } *root;

    public:
        Trie() {
            root = new TrieNode();
        }
        
        void addWord(string &word) {
            root->addWord(word, 0);
        }
        
        bool search(string &word) {
            TrieNode *node = root->get(word, 0);
            return (node && node->hasWord);
        }
        
        int startWith(string &prefix) {
            TrieNode *node = root->get(prefix, 0);
            if (!node) {
                return 0;
            }
            if (node->hasWord) {
                return 2;
            }
            return 1;
        }
        
        void remove(string &word) {
            if (!root->remove(word, 0)) {
                root = new TrieNode();
            }
        }
    };

    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};

    void search(vector<vector<char> > &board, string &word, int i, int j, int m, int n, Trie &dict, vector<string> &result) {
        char c = board[i][j];
        if (c == '\0') {
            return;
        }
        
        board[i][j] = '\0';
        word.push_back(c);
        int r = dict.startWith(word);
        
        if (r) {
            if (r == 2) {
                result.push_back(word);
                dict.remove(word);
            }

            for (int k = 0; k < 4; k++) {
                int ii = i+di[k], jj = j+dj[k];
                if (ii >= 0 && ii < m && jj >= 0 && jj < n) {
                    search(board, word, ii, jj, m, n, dict, result);
                }
            }
        }
        
        board[i][j] = c;
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || board[0].empty() || words.empty()) {
            return result;
        }

        Trie dict;
        for (auto &word : words) {
            dict.addWord(word);
        }
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string word = "";
                search(board, word, i, j, m, n, dict, result);
            }
        }
        
        return result;
    }
};