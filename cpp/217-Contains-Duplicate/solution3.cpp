class Solution {
    int hash[1000000] = {0};

    inline bool insert(int x) {
        int i = (x >> 5);
        int j = 1 << (x & 0x1F);
        if (hash[i] & j) {
            return false;
        }
        hash[i] |= j;
        return true;
    }

public:
    bool containsDuplicate(vector<int>& nums) {
        for (int x : nums) {
            if (!insert(x)) {
                return true;
            }
        }
        return false;
    }
};