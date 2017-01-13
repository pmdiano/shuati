class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            swap(a, b);
        }

        int n = a.length(), m = b.length();
        string result(n, '0');
        int sum = 0, carry = 0;
        int i = n-1, j = m-1;

        for (; j >= 0; i--, j--) {
            sum = (a[i] - '0') + (b[j] - '0') + carry;
            carry = sum / 2;
            result[i] = sum % 2 + '0';
        }

        for (; i >= 0; i--) {
            sum = (a[i] - '0') + carry;
            carry = sum / 2;
            result[i] = sum % 2 + '0';
        }

        if (carry) {
            result = "1" + result;
        }

        return result;
    }
};