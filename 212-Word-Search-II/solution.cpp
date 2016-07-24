class Solution {
    class TrieTree;
    class TrieNode {
        friend class TrieTree;

        static const int R = 26;
        bool hasValue;
        TrieNode* next[R];

        void release() {
            for (int i = 0; i < R; i++) {
                if (next[i]) {
                    next[i]->release();
                    delete next[i];
                }
            }
        }

    public:
        TrieNode() : hasValue(false) {
            for (int i = 0; i < R; i++)
                next[i] = nullptr;
        }
    };

    class TrieTree {
        TrieNode* root;

        void add(TrieNode* node, string& word, int d) {
            if (word.length() == d) {
                node->hasValue = true;
                return;
            }

            if (node->next[word[d] - 'a'] == nullptr) {
                node->next[word[d] - 'a'] = new TrieNode();
            }

            add(node->next[word[d] - 'a'], word, d+1);
        }

        TrieNode* get(TrieNode* node, string& word, int d) {
            if (node == nullptr || word.length() == d) {
                return node;
            }
            return get(node->next[word[d] - 'a'], word, d+1);
        }

        TrieNode* erase(TrieNode* node, string& word, int d) {
            if (word.length() == d) {
                node->hasValue = false;
            } else {
                node->next[word[d] - 'a'] = erase(node->next[word[d] - 'a'], word, d+1);
            }

            if (node->hasValue) {
                return node;
            }
            for (int i = 0; i < TrieNode::R; i++) {
                if (node->next[i] != nullptr) {
                    return node;
                }
            }

            delete node;
            return nullptr;
        }

    public:
        TrieTree() {
            root = new TrieNode();
        }

        ~TrieTree() {
            root->release();
            delete root;
        }

        void insert(string word) {
            add(root, word, 0);
        }

        void erase(string word) {
            if (!erase(root, word, 0)) {
                root = new TrieNode();
            }
        }

        bool hasWord(string word) {
            TrieNode* node = get(root, word, 0);
            return node && node->hasValue;
        }

        bool startsWith(string word) {
            TrieNode* node = get(root, word, 0);
            return node != nullptr;
        }
    };

    int m, n;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};

    void search(vector<vector<char>>& board, int i, int j, TrieTree& trie, string& word, vector<string>& result) {
        word.push_back(board[i][j]);
        board[i][j] = '\0';

        if (trie.hasWord(word)) {
            result.push_back(word);
            trie.erase(word);
        }

        if (trie.startsWith(word)) {
            for (int t = 0; t < 4; t++) {
                int ii = i + di[t];
                int jj = j + dj[t];
                if (0 <= ii && ii < m && 0 <= jj && jj < n && board[ii][jj]) {
                    search(board, ii, jj, trie, word, result);
                }
            }
        }

        board[i][j] = word.back();
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || board[0].empty() || words.empty()) {
            return result;
        }

        TrieTree trie;
        for (string& word : words) {
            trie.insert(word);
        }

        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string word;
                search(board, i, j, trie, word, result);
            }
        }

        return result;
    }
};
