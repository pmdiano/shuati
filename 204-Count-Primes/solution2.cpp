class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int upper = sqrt((float)n);
        vector<int> isPrime(n, 1);

        for (int i = 3; i <= upper; i+=2) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j+=2*i) {
                isPrime[j] = 0;
            }
        }

        int count = 1;
        for (int i = 3; i < n; i+=2) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};