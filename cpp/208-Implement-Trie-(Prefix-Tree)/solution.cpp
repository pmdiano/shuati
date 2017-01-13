class TrieNode {
    const static int R = 26;
    bool hasValue;
    TrieNode* next[R];

    friend class Trie;

    void release() {
        for (int i = 0; i < R; i++) {
            if (next[i]) {
                next[i]->release();
                delete next[i];
            }
        }
    }

public:
    // Initialize your data structure here.
    TrieNode() : hasValue(false) {
        for (int i = 0; i < R; i++) {
            next[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        root->release();
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (node->next[idx] == nullptr) {
                node->next[idx] = new TrieNode();
            }
            node = node->next[idx];
        }
        node->hasValue = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (node->next[idx] == nullptr) {
                return false;
            }
            node = node->next[idx];
        }
        return node->hasValue;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (node->next[idx] == nullptr) {
                return false;
            }
            node = node->next[idx];
        }
        return true;
    }

    // Returns if the word is in the trie. If yes, delete it.
    bool erase(string word) {
        TrieNode *node = root, *ancestor = nullptr;
        vector<TrieNode*> vec;
        int ancestor_index = 0;

        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (node->next[idx] == nullptr) {
                return false;
            }

            bool pathOnly = (node != root) && (!node->hasValue);
            if (pathOnly) {
                for (int j = 0; j < TrieNode::R; j++) {
                    if (j != idx && node->next[j]) {
                        pathOnly = false;
                        break;
                    }
                }
            }

            if (pathOnly) {
                vec.push_back(node);
            } else {
                vec.clear();
                ancestor = node;
                ancestor_index = idx;
            }

            node = node->next[idx];
        }

        for (TrieNode* node : vec) {
            delete node;
        }
        if (ancestor) {
            ancestor->next[ancestor_index] = nullptr;
        }
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");