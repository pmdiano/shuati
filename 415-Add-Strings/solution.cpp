class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int sum = 0, carry = 0;
        int n = max(n1, n2);

        string res(n, '0');
        for (int i1 = n1-1, i2 = n2-1, j = n-1; j >= 0; i1--, i2--, j--) {
            int c1 = i1 >= 0 ? num1[i1] - '0' : 0;
            int c2 = i2 >= 0 ? num2[i2] - '0' : 0;
            sum = c1 + c2 + carry;
            res[j] = sum % 10 + '0';
            carry = sum / 10;
        }

        return carry ? "1" + res : res;
    }
};