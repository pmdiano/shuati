class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        if (m == 0 || n == 0) {
            return "0";
        }

        vector<int> num3(m+n, 0);
        int i, j, carry;
        for (i = m-1; i >= 0; i--) {
            carry = 0;
            for (j = n-1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int sum = a * b + num3[i+j+1] + carry;
                num3[i+j+1] = sum % 10;
                carry = sum / 10;
            }
            num3[i+j+1] = carry;
        }

        i = j = 0;
        while (i < m+n && num3[i] == 0) i++;
        if (i == m+n) {
            return "0";
        } else {
            string ans(m+n-i, '0');
            while (i < m+n) {
                ans[j++] = num[i++] + '0';
            }
            return ans;
        }
    }
};