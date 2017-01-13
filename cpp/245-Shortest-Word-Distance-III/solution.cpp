class Solution {
    int helper(vector<string>& words, string word) {
        int w1 = -1, w2 = -1, dist = INT_MAX;
        bool flag = true;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word) {
                if (flag) {
                    w1 = i;
                    if (w2 != -1) dist = min(dist, w1 - w2);
                } else {
                    w2 = i;
                    dist = min(dist, w2 - w1);
                }
                flag = !flag;
            }
        }
        return dist;
    }
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) return helper(words, word1);

        int w1 = -1, w2 = -1, dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                w1 = i;
                if (w2 != -1) dist = min(dist, w1 - w2);
            } else if (words[i] == word2) {
                w2 = i;
                if (w1 != -1) dist = min(dist, w2 - w1);
            }
        }

        return dist;
    }
};