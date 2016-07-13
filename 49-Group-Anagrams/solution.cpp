class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (const string& str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            hash[word].push_back(str);
        }

        vector<vector<string>> ans;
        for (it = hash.begin(); it != hash.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};