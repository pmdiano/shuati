class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() <= 10) {
            return result;
        }

        char bitmap[1100000] = {0};
        int convert[26] = {0};
        convert['A' - 'A'] = 0;
        convert['T' - 'A'] = 1;
        convert['G' - 'A'] = 2;
        convert['C' - 'A'] = 3;

        int hash = 0;
        for (int i = 0; i < 10; i++) {
            hash <<= 2;
            hash += convert[s[i] - 'A'];
        }

        bitmap[hash] = 1;
        unordered_set<int> mySet;
        for (int i = 10; i < s.length(); i++) {
            hash <<= 2;
            hash &= 0xFFFFF;    // keep right 20 bits
            hash += convert[s[i] - 'A'];
            if (bitmap[hash]) {
                if (mySet.find(hash) == mySet.end()) {
                    mySet.insert(hash);
                    result.push_back(s.substr(i-9, 10));
                }
            } else {
                bitmap[hash] = 1;
            }
        }

        return result;
    }
};