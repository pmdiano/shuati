class Solution {
    void remove_heading_zero(string& num) {
        int i = 0;
        while (num[i] && num[i] == '0') i++;
        num.erase(0, i);
    }

    string multiply_digit(const string& num, char c) {
        int d = c - '0';
        if (d == 0) {
            return "0";
        }

        int n = num.length();
        string ans(n, '0');

        int carry = 0;
        int i = 0;
        for (; i < n; i++) {
            int a = num[n-1-i] - '0';
            int sum = a * d  + carry;
            ans[n-1-i] = sum % 10 + '0';
            carry = sum / 10;
        }

        if (carry) {
            ans = string(1, '0'+carry) + ans;
        }

        return ans;
    }

    string add_str(const string& num1, const string& num2) {
        int m = num1.length(), n = num2.length(), l = max(m, n);
        string ans(l, '0');

        int carry = 0;
        int i = 0;
        for (; i < min(m, n); i++) {
            int a = num1[m-1-i] - '0';
            int b = num2[n-1-i] - '0';
            int sum = a + b + carry;
            ans[l-1-i] = sum % 10 + '0';
            carry = sum / 10;
        }

        for (; i < m; i++) {
            int a = num1[m-1-i] - '0';
            int sum = a + carry;
            ans[l-1-i] = sum % 10 + '0';
            carry = sum / 10;
        }

        for (; i < n; i++) {
            int b = num2[n-1-i] - '0';
            int sum = b + carry;
            ans[l-1-i] = sum % 10 + '0';
            carry = sum / 10;
        }

        if (carry) {
            ans = "1" + ans;
        }

        return ans;
    }

public:
    string multiply(string num1, string num2) {
        remove_heading_zero(num1);
        remove_heading_zero(num2);
        
        if (num1.empty() || num2.empty()) {
            return "0";
        }

        string ans = "0";
        for (int i = 0; i < num1.length(); i++) {
            string val = multiply_digit(num2, num1[i]);

            if (val != "0") {
                val += string(num1.length()-1-i, '0');
                ans = add_str(ans, val);
            }
        }

        return ans;
    }
};