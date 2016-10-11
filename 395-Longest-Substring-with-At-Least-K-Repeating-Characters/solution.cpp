class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        int count[26] = {0};
        for (char c : s) {
            count[c-'a']++;
        }

        int minCount = k;
        char c;
        for (int i = 0; i < 26; i++) {
            if (count[i] && count[i] < minCount) {
                minCount = count[i];
                c = 'a'+i;
            }
        }
        if (minCount == k) {
            return s.size();
        }

        int res = 0;
        size_t i = 0, j = 0;
        do {
            j = s.find_first_of(c, i);
            res = max(res, longestSubstring(s.substr(i, j-i), k));
            i = j+1;
            
        } while (j != string::npos);

        return res;
    }
};