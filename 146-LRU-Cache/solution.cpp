class LRUCache{
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode(int k, int v) : key(k), val(v), next(nullptr) {}
    };

    unordered_map<int, ListNode*> hash;
    ListNode *head;
    ListNode *tail;
    int capacity;

    void move_to_tail(int key) {
        ListNode* prev = hash[key];
        ListNode* node = prev->next;

        if (node != tail) {
            prev->next = node->next;
            if (node->next) {
                hash[node->next->key] = prev;
            }

            tail->next = node;
            node->next = nullptr;
    
            hash[key] = tail;
            tail = node;
        }
    }

    void remove_head_next() {
        ListNode* node = head->next;

        if (tail == node) {
            tail = head;
        }

        if (node) {
            hash.erase(node->key);
            head->next = node->next;
            if (head->next) {
                hash[head->next->key] = head;
            }
            delete node;
        }
    }

public:
    LRUCache(int capacity) {
        this->head = new ListNode(0, 0);
        this->tail = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        move_to_tail(key);
        return hash[key]->next->val;
    }
    
    void set(int key, int value) {
        if (capacity <= 0) {
            return;
        }

        if (hash.find(key) == hash.end()) {
            if (hash.size() == capacity) {
                remove_head_next();
            }
            ListNode* node = new ListNode(key, value);
            tail->next = node;
            hash[key] = tail;
            tail = node;
            return;
        }

        move_to_tail(key);
        tail->val = value;
    }
};
