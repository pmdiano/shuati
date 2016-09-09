class HitCounter {
    map<int, int> hash;
    void update(int timestamp) {
        auto it = hash.upper_bound(timestamp-300);
        if (it != hash.begin()) {
            hash.erase(hash.begin(), it);
        }
    }
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        update(timestamp);
        hash[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        update(timestamp);
        int res = 0;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            res += it->second;
        }
        return res;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */