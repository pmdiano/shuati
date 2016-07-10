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
            int x2 = x * 10 + d;
            if (x2 < 0 || (x2-d)/10 != x) {
                // Overflow
                return negative ? INT_MIN : INT_MAX;
            }
            x = x2;
            i++;
        }

        return negative ? -x : x;
    }
};