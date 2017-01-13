class Solution {
public:
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                int j = i+len-1;
                if (len <= 2) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] = isPalindrome[i+1][j-1] && (s[i] == s[j]);
                }
            }
        }

        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            if (!isPalindrome[0][i]) {
                f[i] = i;
                for (int j = 0; j < i; j++) {
                    if (f[j] + 1 < f[i] && isPalindrome[j+1][i]) {
                        f[i] = f[j] + 1;
                    }
                }
            }
        }

        return f[n-1];
    }
};
