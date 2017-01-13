class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        size_t i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (abbr[j] == '0') {
                return false;
            } else if (isdigit(abbr[j])) {
                int k = j;
                while (isdigit(abbr[j])) j++;
                i += atoi(abbr.substr(k, j-k).c_str());
            } else {
                if (word[i++] != abbr[j++]) {
                    return false;
                }
            }
        }
        return i == word.size() && j == abbr.size();
    }
};