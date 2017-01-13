class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if (strs.empty()) {
            return prefix;
        }

        for (int j = 0; j < strs[0].length(); j++) {
            const char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] != c) {
                    return prefix;
                }
            }
            prefix += c;
        }

        return prefix;
    }
};