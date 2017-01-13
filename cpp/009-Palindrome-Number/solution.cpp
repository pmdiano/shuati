class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int a = x/10, p10 = 1, i, j;
        while (a) {
            p10 *= 10;
            a /= 10;
        }

        while (x) {
            i = x / p10;
            j = x % 10;
            x = (x - i*p10) / 10;
            p10 /= 100;
            
            if (i != j) {
                return false;
            }
        }

        return true;
    }
};