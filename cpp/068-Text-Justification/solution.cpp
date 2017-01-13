class Solution {
    string generateLine(vector<string>& words, int start, int end, int maxWidth) {
        int n = end - start + 1;
        if (n == 1) {
            return words[start] + string(maxWidth - words[start].length(), ' ');
        }

        int width = 0;
        for (int i = start; i <= end; i++) {
            width += words[i].length();
        }

        int spaceWidth = maxWidth - width;
        int rest = spaceWidth % (n-1);
        vector<int> spaces(n-1, spaceWidth / (n-1));
        for (int i = 0; rest; i++, rest--) {
            spaces[i]++;
        }

        string result;
        for (int i = 0; i < n-1; i++) {
            result += words[start+i] + string(spaces[i], ' ');
        }
        result += words[end];
        return result;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int width = 0, start = 0, i = 0;

        while (i < words.size()) {
            int newWidth = width == 0 ? words[i].length() : width + 1 + words[i].length();
            if (newWidth == maxWidth) {
                result.push_back(generateLine(words, start, i, maxWidth));
                i++;
                width = 0, start = i;
            } else if (newWidth > maxWidth) {
                result.push_back(generateLine(words, start, i-1, maxWidth));
                width = 0, start = i;
            } else {
                i++;
                width = newWidth;
            }
        }

        if (start < i) {
            result.push_back(generateLine(words, start, i-1, width) + string(maxWidth - width, ' '));
        }

        return result;
    }
};