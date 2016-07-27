class Solution {
    string normalize(string str) {
        if (str.empty()) return str;
        string res = str;
        int offset = 26 - ((int)str[0] - 'a');
        for (int i = 0; i < res.length(); i++) {
            int a = str[i] + offset;
            if (a > 'z') a -= 26;
            res[i] = a;
        }
        return res;
    }

public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hash;
        for (string str : strings) {
            hash[normalize(str)].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(hash.size());
        for (auto it = hash.begin(); it != hash.end(); it++) {
            res.push_back(it->second);
        }

        return res;
    }
};