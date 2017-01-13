class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (strs[i][j] && prefix[j] && strs[i][j] == prefix[j]) j++;
            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};