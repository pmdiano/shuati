class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        int i = 0, j = 0;
        while (s[i] && s[i] != '+') i++;
        j = i+1;
        while (j < s.length()) {
            while (s[j] && s[j] != '+') j++;
            if (s[j] && j == i+1) {
                string t = s;
                t[i] = '-', t[j] = '-';
                ans.push_back(t);
            }
            i = j, j = i+1;
        }
        return ans;
    }
};