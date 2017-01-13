class Solution {
    void dfs(string& word, int pos, int n, string curr, vector<string>& res) {
        if (pos == (int)word.length()) {
            if (n) curr += to_string(n);
            res.push_back(curr);
            return;
        }

        // Option 1, use original character
        string v1 = curr;
        if (n) v1 += to_string(n);
        v1.push_back(word[pos]);
        dfs(word, pos+1, 0, v1, res);

        // Option 2, use generalization
        dfs(word, pos+1, n+1, curr, res);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(word, 0, 0, "", res);
        return res;
    }
};