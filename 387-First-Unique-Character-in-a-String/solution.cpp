class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> pos(26, -1);
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (pos[s[i]-'a'] < 0) pos[s[i]-'a'] = i;
            cnt[s[i]-'a']++;
        }
        int j = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1 && pos[i] < j) {
                j = pos[i];
            }
        }
        return j == INT_MAX ? -1 : j;
    }
};