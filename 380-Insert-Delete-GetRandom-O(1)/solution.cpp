class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> hash;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.count(val)) {
            return false;
        }

        nums.push_back(val);
        hash[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!hash.count(val)) {
            return false;
        }

        int pos = hash[val];
        hash[nums[nums.size() - 1]] = pos;
        nums[pos] = nums[nums.size() - 1];
        hash.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % (int)nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */