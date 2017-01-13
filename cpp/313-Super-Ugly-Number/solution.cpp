class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 1);
        vector<int> index(primes.size(), 0);
        vector<int> next(primes.size(), 0);
        int i = 1;

        while (i < n) {
            int m = numeric_limits<int>::max();
            for (int j = 0; j < primes.size(); j++) {
                next[j] = res[index[j]] * primes[j];
                m = min(m, next[j]);
            }

            for (int j = 0; j < primes.size(); j++) {
                if (m == next[j]) {
                    index[j]++;
                }
            }

            res[i++] = m;
        }

        return res[n-1];
    }
};