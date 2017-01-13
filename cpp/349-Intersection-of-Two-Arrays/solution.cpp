class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        for (int n : nums1) {
            hash.insert(n);
        }

        vector<int> ans;
        for (int n : nums2) {
            auto it = hash.find(n);
            if (it != hash.end()) {
                hash.erase(it);
                ans.push_back(n);
            }
        }

        return ans;
    }
};