class ValidWordAbbr {
    string getAbbr(string& word) {
        if (word.length() <= 2) {
            return word;
        }
        return string(1, word.front()) + to_string(word.length() - 2) + string(1, word.back());
    }

    unordered_map<string, string> hash;

public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            string abbr = getAbbr(word);
            if (hash.find(abbr) != hash.end() && hash[abbr] != word) {
                // collision
                hash[abbr] = "";
            } else {
                hash[abbr] = word;
            }
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return hash.find(abbr) == hash.end() || hash[abbr] == word;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");