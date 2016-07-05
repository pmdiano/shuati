class LRUCache{
    struct ListNode {
        int key;
        int value;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> prevHash;
    int capacity;

    void move_to_tail(int key) {
        ListNode* prev = prevHash[key];
        ListNode* node = prev->next;
        if (node == tail) {
            // Already at tail, nothing to do
            return;
        }

        // Take out node, need to update node's next's hash
        prevHash[node->next->key] = prev;
        prev->next = node->next;

        // Insert node to tail, update hash, update tail
        prevHash[node->key] = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
    }

    void insert_at_tail(int key, int value) {
        ListNode* node = new ListNode(key, value);
        prevHash[key] = tail;

        tail->next = node;
        tail = node;
    }

    void remove_head_next() {
        if (head->next == tail) {
            // Only one node, reset everything
            prevHash.clear();
            delete tail;
            tail = head;
            return;
        }

        ListNode* node = head->next;
        ListNode* next = node->next;

        // Remove node
        prevHash.erase(node->key);
        delete node;
        head->next = next;

        // Update next node's hash
        prevHash[next->key] = head;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new ListNode(0, 0);
        this->tail = this->head;
    }

    ~LRUCache() {
        while (head) {
            ListNode* node = head;
            head = head->next;
            delete node;
        }
    }

    int get(int key) {
        if (prevHash.find(key) == prevHash.end()) {
            return -1;
        }

        move_to_tail(key);
        return prevHash[key]->next->value;
    }
    
    void set(int key, int value) {
        if (capacity <= 0) {
            return;
        }

        if (prevHash.find(key) != prevHash.end()) {
            move_to_tail(key);
            prevHash[key]->next->value = value;
            return;
        }

        if (prevHash.size() == capacity) {
            remove_head_next();
        }

        insert_at_tail(key, value);
    }
};
