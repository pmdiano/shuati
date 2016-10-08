class LRUCache{
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity): cap(capacity) {
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        m[key] = l.begin();
        return l.front().second;
    }

    void set(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();

        if (l.size() > cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
    }
};