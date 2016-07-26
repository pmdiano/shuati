class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        bool same = word1 == word2;
        int w1 = -1, w2 = -1, dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                w1 = i;
                if (w2 != -1) dist = min(dist, w1-w2);
                if (same) w2 = w1;
            } else if (words[i] == word2) {
                w2 = i;
                if (w1 != -1) dist = min(dist, w2-w1);
            }
        }
        return dist;
    }
};