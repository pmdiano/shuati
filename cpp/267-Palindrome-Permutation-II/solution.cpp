class Solution {
    void dfs(string& candidates, vector<int>& count, int n, string& current, vector<string>& ans, char odd) {
        if (n/2 == current.length()) {
            string s2 = current;
            reverse(s2.begin(), s2.end());
            if (n%2 == 0) {
                ans.push_back(current + s2);
            } else {
                ans.push_back(current + odd + s2);
            }
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            if (count[i] >= 2) {
                current.push_back(candidates[i]);
                count[i] -= 2;
                dfs(candidates, count, n, current, ans, odd);
                count[i] += 2;
                current.pop_back();
            }
        }
    }

public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        string current;

        unordered_map<char, int> hash;
        for (char c : s) {
            hash[c]++;
        }

        bool allowOneOdd = (s.length() % 2 != 0);
        for (auto& p : hash) {
            if (p.second % 2) {
                if (!allowOneOdd) {
                    return ans;
                }
                allowOneOdd = false;
            }
        }

        string candidates(hash.size(), '0');
        vector<int> count(hash.size(), 0);
        int i = 0;
        char odd = '0';
        for (auto it = hash.begin(); it != hash.end(); it++) {
            candidates[i] = it->first;
            count[i] = it->second;
            if (count[i] % 2) {
                odd = candidates[i];
            }
            i++;
        }

        dfs(candidates, count, s.length(), current, ans, odd);

        return ans;
    }
};
