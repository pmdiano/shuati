class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        const vector<int> factors({2, 3, 5});
        for (int a : factors) {
            while (num % a == 0) {
                num /= a;
            }
        }

        return num == 1;
    }
};