class Solution {
    void dfs(vector<string>& ans, string& current, int n, int left, int right) {
        if (current.length() == 2*n) {
            ans.push_back(current);
            return;
        }

        if (left < n) {
            current += '(';
            dfs(ans, current, n, left+1, right);
            current.resize(current.length() - 1);
        }

        if (right < left) {
            current += ')';
            dfs(ans, current, n, left, right+1);
            current.resize(current.length() - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return vector<string>();
        }

        vector<string> ans;
        string current;
        dfs(ans, current, n, 0, 0);

        return ans;
    }
};