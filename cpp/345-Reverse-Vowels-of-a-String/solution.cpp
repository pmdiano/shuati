class Solution {

public:
    string reverseVowels(string s) {
        char f[256];
        const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        memset(f, 0, sizeof(f));
        for (int i = 0; i < sizeof(vowels); i++) {
            f[vowels[i]] = 1;
        }

        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!f[s[i]]) {
                i++;
            } else if (!f[s[j]]) {
                j--;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};