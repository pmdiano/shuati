class Solution {
    void search(string& s, int pos, vector<vector<bool>>& isPalindrome, vector<string>& current, vector<vector<string>>& ans)
    {
        if (pos == s.length()) {
            ans.push_back(current);
            return;
        }

        for (int i = pos; i < s.length(); i++) {
            if (isPalindrome[pos][i]) {
                current.push_back(s.substr(pos, i-pos+1));
                search(s, i+1, isPalindrome, current, ans);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if (s.empty()) {
            return ans;
        }

        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                if (len <= 2) {
                    isPalindrome[i][i+len-1] = (s[i] == s[i+len-1]);
                } else {
                    isPalindrome[i][i+len-1] = isPalindrome[i+1][i+len-2] && (s[i] == s[i+len-1]);
                }
            }
        }

        vector<string> current;
        search(s, 0, isPalindrome, current, ans);
        return ans;
    }
};
