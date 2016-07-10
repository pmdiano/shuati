class Solution {
public:
    int myAtoi(string str) {
        int i = 0;

        // Remove heading whitespaces
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') i++;

        // Check if valid
        if (str[i] != '+' && str[i] != '-' && !('0' <= str[i] && str[i] <= '9')) return 0;

        bool negative = str[i] == '-';
        if (str[i] == '+' || str[i] == '-') i++;

        int x = 0;
        while ('0' <= str[i] && str[i] <= '9') {
            int d = str[i] - '0';
            if (x > INT_MAX/10 || (x == INT_MAX/10 && d > 7)) {
                // Overflow
                return negative ? INT_MIN : INT_MAX;
            }
            x = x * 10 + d;
            i++;
        }

        return negative ? -x : x;
    }
};