class WordDictionary {
    class TrieNode {
        friend class WordDictionary;

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
    } *root;

    void add(TrieNode* node, const string& word, int d) {
        if (d == word.length()) {
            node->hasValue = true;
            return;
        }

        if (node->next[word[d] - 'a'] == nullptr) {
            node->next[word[d] - 'a'] = new TrieNode();
        }

        add(node->next[word[d] - 'a'], word, d+1);
    }

    bool find(TrieNode* node, const string& word, int d) {
        if (node == nullptr) {
            return false;
        }

        if (d == word.length()) {
            return node->hasValue;
        }

        if (word[d] != '.') {
            return find(node->next[word[d] - 'a'], word, d+1);
        } else {
            for (int i = 0; i < TrieNode::R; i++) {
                if (find(node->next[i], word, d+1)) {
                    return true;
                }
            }
            return false;
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        root->release();
        delete root;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        add(root, word, 0);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return find(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");