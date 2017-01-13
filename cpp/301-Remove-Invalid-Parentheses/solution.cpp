class Solution {
    bool isValid(string& str) {
        int left = 0;
        for (char c : str) {
            if (c == '(') left++;
            else if (c == ')' && left-- == 0) return false;
        }
        return left == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        bool found = false;
        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            s = q.front();
            q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i+1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    visited.insert(t);
                }
            }
        }

        return res;
    }
};