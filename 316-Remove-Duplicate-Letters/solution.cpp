class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[256] = {0}, visited[256] = {0};
        string res = "0";
        for (auto c : s) ++count[c];
        for (auto c : s) {
            --count[c];
            if (visited[c]) continue;
            while (c < res.back() && count[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res.push_back(c);
            visited[c] = 1;
        }
        return res.substr(1);
    }
};