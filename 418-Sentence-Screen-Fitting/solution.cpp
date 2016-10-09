class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        if (sentence.empty()) return 0;
        int n = sentence.size();

        // number of words can fit in a row if the row starts with sentence[i]
        vector<int> count(n, 0);
        for (int i = 0; i < sentence.size(); i++) {
            int len = -1, j = i;
            while (len + 1 + (int)sentence[j].size() <= cols) {
                len += 1 + (int)sentence[j].size();
                j = (j + 1) % n;
                count[i]++;
            }
            if (len == -1) return 0;
        }

        int total = 0, start = 0;
        for (int i = 0; i < rows; i++) {
            total += count[start];
            start += count[start];
            start %= n;
        }

        return total / n;
    }
};