class Solution {
    bool check(string& num, int i, int j, int k) {
        // num.substr(i, j-i) is first number
        // num.substr(j, k-j) is second number
        if (k == num.length()) return true;
        if ((num[i] == '0' && j-i>1) || (num[j] == '0' && k-j>1)) return false;
        if (num.length() - k < max(j-i, k-j)) return false;

        long long num1 = stoll(num.substr(i, j-i));
        long long num2 = stoll(num.substr(j, k-j));
        string sum = to_string(num1 + num2);

        if (num.substr(k, sum.length()) == sum) {
            return check(num, j, k, k+sum.length());
        } else {
            return false;
        }
    }

public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        for (int i = 1; i < num.length() - 1; i++) {
            for (int j = i+1; j < num.length(); j++) {
                if (check(num, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};