class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.length() < words.size() * words[0].length()) {
            return ans;
        }

        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            if (hash.find(words[i]) == hash.end()) {
                hash[words[i]] = 1;
            } else {
                hash[words[i]]++;
            }
        }

        int n = words[0].length();
        int count = words.size();
        unordered_map<string, int> tofind;

        for (int i = 0; i <= s.length() - n*count; i++) {
            tofind.clear();
            int j = 0;

            for (; j < count; j++) {
                string word = s.substr(i+j*n, n);
                if (hash.find(word) == hash.end()) {
                    break;
                }

                if (tofind.find(word) == tofind.end()) {
                    tofind[word] = 1;
                } else {
                    tofind[word]++;
                }

                if (tofind[word] > hash[word]) {
                    break;
                }
            }

            if (j == count) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
