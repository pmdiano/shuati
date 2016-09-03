class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = {0};
        while (res.size() < num+1) {
            int sz = res.size(), i = 0;
            while (i < sz && res.size() < num+1)
                res.push_back(res[i++]+1);
        }
        return res;
    }
};