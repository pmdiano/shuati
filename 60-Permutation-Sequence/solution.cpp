class Solution {
public:
    string getPermutation(int n, int k) {
        string ans(n, '0');
        vector<int> used(n, 0);

        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }

        if (k <= 0 || k > factorial) {
            return ans;
        }

        k--;
        for (int i = 0; i < n; i++) {
            factorial /= (n-i);
            int j = k / factorial;
            k = k % factorial;

            for (int t = 0; t < n; t++) {
                if (used[t]) {
                    continue;
                }

                if (j == 0) {
                    ans[i] = '1' + t;
                    used[t] = 1;
                    break;
                }

                j--;
            }
        }

        return ans;
    }
};