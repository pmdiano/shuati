class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        for (int i = 0, w; i < words.size(); i = w) {
            int len = -1;
            for (w = i; w < words.size() && len + words[w].length() + 1 <= maxWidth; w++) {
                len += words[w].length() + 1;
            }

            int space = 1, extra = 0;
            if (w != i+1 && w != words.size()) {
                // Additional 1 for the default one space between words
                space = (maxWidth - len) / (w - i - 1) + 1;
                extra = (maxWidth - len) % (w - i - 1);
            }

            string line = words[i];
            for (int j = i+1; j < w; j++) {
                line += string(extra-- > 0 ? space+1 : space, ' ');
                line += words[j];
            }

            line += string(maxWidth - line.length(), ' ');
            result.push_back(line);
        }

        return result;
    }
};