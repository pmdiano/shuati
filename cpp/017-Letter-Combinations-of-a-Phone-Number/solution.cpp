class Solution {
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void search(string& digits, int pos, string& current, vector<string>& ans) {
        if (pos == digits.length()) {
            ans.push_back(current);
            return;
        }

        string& candidates = letters[digits[pos] - '0'];
        if (candidates.length() == 0) {
            search(digits, pos+1, current, ans);
        } else {
            for (int i = 0; i < candidates.length(); i++) {
                current.push_back(candidates[i]);
                search(digits, pos+1, current, ans);
                current.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string current;
        vector<string> ans;
        if (digists.empty()) {
            return ans;
        }

        search(digits, 0, current, ans);
        return ans;
    }
};