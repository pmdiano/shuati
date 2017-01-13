class Solution {
    char nonzero[5][2] = {
        {'1', '1'},
        {'8', '8'},
        {'6', '9'},
        {'9', '6'}
    };

    void helper(int p, string& curr, vector<string>& result) {
        int q = curr.length() - p - 1;
        if (p > q) {
            result.push_back(curr);
            return;
        }

        if (p > 0 || (p == 0 && q == 0)) {
            curr[p] = '0';
            curr[q] = '0';
            helper(p+1, curr, result);
        }
        for (int i = 0; i < (p == q ? 2 : 4); i++) {
            curr[p] = nonzero[i][0];
            curr[q] = nonzero[i][1];
            helper(p+1, curr, result);
        }
    }

public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if (n <= 0) return result;

        string curr(n, '\0');
        helper(0, curr, result);
        return result;
    }
};