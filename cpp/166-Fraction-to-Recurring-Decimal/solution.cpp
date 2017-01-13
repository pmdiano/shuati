class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "";
        }
        if (numerator == 0) {
            return "0";
        }

        bool negative = (numerator < 0) ^ (denominator < 0);
        long long num = numerator < 0 ? -(long long)numerator : numerator;
        long long den = denominator < 0 ? -(long long)denominator : denominator;

        long long a = num / den;
        int start = INT_MAX, i;
        vector<int> decimal;
        unordered_map<int, int> hash;

        num %= den;
        num *= 10;
        hash[num] = 0;

        while (num) {
            if (num < den) {
                decimal.push_back(0);
                num *= 10;
            } else {
                decimal.push_back(num / den);
                num %= den;
                num *= 10;
            }

            if (hash.find(num) == hash.end()) {
                hash[num] = decimal.size();
            } else {
                start = hash[num];
                break;
            }
        }

        string result;
        if (negative) {
            result.push_back('-');
        }
        result += to_string(a);
        if (decimal.empty()) {
            return result;
        }

        result.push_back('.');
        for (i = 0; i < decimal.size() && i < start; i++) {
            result.push_back('0' + decimal[i]);
        }
        if (i == decimal.size()) {
            return result;
        }

        result.push_back('(');
        for (int i = start; i < decimal.size(); i++) {
            result.push_back('0' + decimal[i]);
        }
        result.push_back(')');

        return result;
    }
};