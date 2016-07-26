class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        bool same = word1 == word2;
        long long w1 = INT_MAX, w2 = -INT_MAX, dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                w1 = i;
                if (same) swap(w1, w2);
                dist = min(dist, abs(w1-w2));
            } else if (words[i] == word2) {
                w2 = i;
                dist = min(dist, abs(w1-w2));
            }
        }

        return (int)dist;
    }
};