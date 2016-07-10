class Solution {
public:
    string intToRoman(int num) {
        static const string thousands[] = {"", "M", "MM", "MMM"};
        static const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        if (num <= 0 || num >= 4000) {
            return "";
        }

        int i1 = num / 1000;
        num %= 1000;
        int i2 = num / 100;
        num %= 100;
        int i3 = num / 10;
        num %= 10;
        int i4 = num;

        return thousands[i1] + hundreds[i2] + tens[i3] + ones[i4];
    }
};