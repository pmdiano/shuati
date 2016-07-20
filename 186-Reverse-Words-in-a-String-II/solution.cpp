class Solution {
    void reverse(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
public:
    void reverseWords(string &s) {
        int i = 0, j = 0, n = s.length();
        while (i < n) {
            while (j < n && s[j] != ' ') j++;
            reverse(s, i, j-1);
            i = ++j;
        }
        reverse(s, 0, n-1);
    }
};