class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int exists[26] = {0};
        unordered_map<string, char> hash;
        size_t pos = 0, next;
        string word;

        for (int i = 0; i < pattern.length(); i++) {
            if (pos == string::npos) return false;
            if ((next = str.find(' ', pos)) == string::npos) {
                word = str.substr(pos);
                pos = string::npos;
            } else {
                word = str.substr(pos, next - pos);
                pos = next + 1;
            }

            if (exists[pattern[i]-'a'] && hash[word] != pattern[i]) {
                return false;
            }
            if (!exists[pattern[i]-'a'] && hash.find(word) != hash.end()) {
                return false;
            }
            hash[word] = pattern[i];
            exists[pattern[i] - 'a'] = 1;
        }

        return pos == string::npos;
    }
};