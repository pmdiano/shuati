class Solution {
    bool search(string& pattern, int pattern_pos, string& str, int str_pos, vector<int>& char_set, unordered_map<string, char>& hash) {
        if (pattern_pos == pattern.length() && str_pos == str.length()) return true;
        if (pattern_pos == pattern.length() || str_pos == str.length()) return false;

        for (int i = str_pos+1; i <= str.length(); i++) {
            string word = str.substr(str_pos, i - str_pos);
            char c = pattern[pattern_pos];
            bool ok = false, new_add = false;

            if (!char_set[c-'a'] && hash.find(word) == hash.end()) {
                ok = true;
                new_add = true;
                char_set[c-'a'] = 1;
                hash[word] = c;
            } else if (char_set[c-'a'] && hash.find(word) != hash.end() && hash[word] == c) {
                ok = true;
            }

            if (ok && search(pattern, pattern_pos+1, str, i, char_set, hash)) {
                return true;
            }
            if (new_add) {
                char_set[c-'a'] = 0;
                hash.erase(word);
            }
        }

        return false;
    }

public:
    bool wordPatternMatch(string pattern, string str) {
        vector<int> char_set(26, 0);
        unordered_map<string, char> hash;
        return search(pattern, 0, str, 0, char_set, hash);
    }
};
