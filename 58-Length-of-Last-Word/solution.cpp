class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, j;
        for (j = s.length() - 1; j >= 0 && s[j] == ' '; j--);
        for (i = j; i >= 0 && s[i] != ' '; i--);
        return j - i;
    }
};