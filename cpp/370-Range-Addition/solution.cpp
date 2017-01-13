class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        length = max(length, 0);
        vector<int> res(length, 0);

        for (auto& update : updates) {
            res[update[0]] += update[2];
            if (update[1] < length - 1) {
                res[update[1]+1] -= update[2];
            }
        }

        for (int i = 1; i < length; i++) {
            res[i] += res[i-1];
        }
        return res;
    }
};