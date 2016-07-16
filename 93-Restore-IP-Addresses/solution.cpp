class Solution {
    void search(string& s, int pos, vector<string>& bytes, vector<string>& result) {
        if (pos == s.length() && bytes.size() == 4) {
            result.push_back(bytes[0]);
            for (int i = 1; i < 4; i++) {
                result.back() += "." + bytes[i];
            }
            return;
        }

        int n = 4 - bytes.length();
        int len = s.length() - pos;
        if (len < n || len > n*3) {
            return;
        }

        for (int i = pos+1; i <= pos+3 && i <= s.length(); i++) {
            if (i < pos+3 || s[pos] <= '2' || s[pos+1] <= '4' || (s[pos+1] == '5' && s[pos+2] <= '5')) {
                bytes.push_back(s.substr(pos, i-pos));
                search(s, i, bytes, result);
                bytes.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> bytes;
        search(s, 0, bytes, result);
        return result;
    }
};