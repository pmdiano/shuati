class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }

        vector<int> lens(words.size(), 0), bits(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            lens[i] = (int)words[i].length();
            for (char c : words[i]) {
                bits[i] |= (1 << (c - 'a'));
            }
        }

        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if ((bits[i] & bits[j]) == 0 && lens[i] * lens[j] > res) {
                    res = lens[i] * lens[j];
                }
            }
        }

        return res;
    }
};