class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
            if (lhs.first != rhs.first) {
                return lhs.first > rhs.first;
            }
            return lhs.second < rhs.second;
        });

        vector<pair<int, int>> res;
        for (int i = 0; i < people.size(); i++) {
            res.insert(res.begin() + people[i].second, people[i]);
        }

        return res;
    }
};