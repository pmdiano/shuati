class WordDistance {
    unordered_map<string, vector<int>> hash;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            hash[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int dist = INT_MAX, i = 0, j = 0;
        vector<int>& pos1 = hash[word1];
        vector<int>& pos2 = hash[word2];
        while (i < pos1.size() && j < pos2.size()) {
            dist = min(dist, abs(pos1[i] - pos2[j]));
            if (pos1[i] < pos2[j])
                i++;
            else
                j++;
        }
        while (i < pos1.size()) dist = min(dist, abs(pos1[i++] - pos2.back()));
        while (j < pos2.size()) dist = min(dist, abs(pos2[j++] - pos1.back()));
        return dist;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");