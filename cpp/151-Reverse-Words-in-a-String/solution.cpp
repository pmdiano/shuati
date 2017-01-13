class Solution {
public:
    void reverseWords(string &s) {
        string ans;
        const char* pch = strtok(const_cast<char*>(s.c_str()), " ");
        while (pch) {
            if (ans.length()) ans = " " + ans;
            ans = string(pch) + ans;
            pch = strtok(NULL, " ");
        }
        s = ans;
    }
};