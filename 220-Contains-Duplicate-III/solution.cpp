class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        int i = 0, j = 0;
        for (; i < nums.size(); i++) {
            if (i-j > k) {
                if (m[nums[j]] == j) {
                    m.erase(nums[j]);
                }
                j++;
            }

            auto a = m.lower_bound(nums[i] - t);
            if (a != m.end() && a->first - nums[i] <= t) {
                return true;
            }

            m[nums[i]] = i;
        }

        return false;
    }
};