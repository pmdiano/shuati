class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }

        int res = 0;
        vector<int> bits(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                bits[i] |= (1 << (c - 'a'));
            }
            for (int j = 0; j < i; j++) {
                if ((bits[i] & bits[j]) == 0 && words[i].length() * words[j].length() > res) {
                    res = words[i].length() * words[j].length();
                }
            }
        }

        return res;
    }
};