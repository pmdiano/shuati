class Solution {
public:
    string intToRoman(int num) {
        static const int nums[] =     {1000, 900,  500, 400,  100, 90,   50,  40,   10,   9,    5,   4,    1};
        static const string romans[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int i = 0;
        string ans;
        while (num) {
            int times = num / nums[i];
            num -= (times * nums[i]);
            while (times--) {
                ans += romans[i];
            }
            i++;
        }

        return ans;
    }
};