class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hash;
        for (char c : s) {
            hash[c]++;
        }

        bool allowOneOdd = (s.length() % 2 != 0);
        for (auto& p : hash) {
            if (p.second % 2) {
                if (!allowOneOdd) {
                    return false;
                }
                allowOneOdd = false;
            }
        }

        return true;
    }
};