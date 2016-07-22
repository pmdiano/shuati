class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int x : nums) {
            if (hash.find(x) != hash.end())
                return true;
            else
                hash.insert(x);
        }
        return false;
    }
};