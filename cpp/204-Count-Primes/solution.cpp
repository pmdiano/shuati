class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        int upper = sqrt((float)n);
        vector<int> isPrime(n, 1);

        for (int i = 2; i <= upper; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j+=i) {
                isPrime[j] = 0;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};