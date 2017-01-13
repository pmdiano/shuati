class Solution {
    // num is positive number less than 1000
    string helper(int num) {
        string ones[] = {"dummy", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"dummy", "dummy", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string ans;
        if (num >= 100) {
            ans += ones[num / 100] + " " + "Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            ans += tens[num / 10] + " ";
            num %= 10;
        }
        if (num) {
            ans += ones[num] + " ";
        }

        return ans.substr(0, ans.length() - 1);
    }

public:
    string numberToWords(int num) {
        int thousands[3] = {1000000000, 1000000, 1000};
        string thousands_word[3] = {"Billion", "Million", "Thousand"};

        string ans;
        for (int i = 0; i < 3; i++) {
            if (num / thousands[i]) {
                ans += helper(num / thousands[i]) + " " + thousands_word[i] + " ";
                num %= thousands[i];
            }
        }
        if (num) {
            ans += helper(num) + " ";
        }

        if (ans.empty()) {
            return "Zero";
        } else {
            return ans.substr(0, ans.length() - 1);
        }
    }
};