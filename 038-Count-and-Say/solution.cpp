class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        // 1211 --> 111221 --> 312211 --> 13112221  --> 1113213211 --> 31131211131221
        string s = "1";
        for (; n >= 2; n--) {
            string t;
            int i = 0;
            while (s[i]) {
                int j = i;
                while (s[j] == s[i]) j++;
                t += to_string(j-i) + s[i];
                i = j;
            }
            s = t;
        }

        return s;
    }
};