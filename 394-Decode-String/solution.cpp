class Solution {
public:
    string decodeString(string s) {
        if (s.find('[') == string::npos) {
            return s;
        }

        int i = 0, n = s.size();
        while (isalpha(s[i])) i++;
        string res = s.substr(0, i);
        int repeat = atoi(&s[i]);

        int j = s.find_first_of('[', i) + 1, k = j, cnt = 1;
        while (cnt) {
            if (s[k] == '[') cnt++;
            else if (s[k] == ']') cnt--;
            k++;
        }

        string sub = decodeString(s.substr(j, k-1-j));
        while (repeat--) res += sub;
        res += decodeString(s.substr(k));

        return res;
    }
};