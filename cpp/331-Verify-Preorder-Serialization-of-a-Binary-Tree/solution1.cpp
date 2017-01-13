class Solution {
public:
    bool isValidSerialization(string preorder) {
        const char delimiter = ',';
        const char nullnode = '#';

        int openning = 1, pos = 0;
        preorder.push_back(delimiter);
        while (preorder[pos]) {
            int i = pos;
            while (preorder[i] != delimiter) i++;
            //cout << preorder.substr(pos, i-pos) << ": " << openning << endl;
            if (i == pos + 1 && preorder[pos] == nullnode) {
                if (--openning  < 0) {
                    return false;
                }
            } else {
                if (openning == 0) {
                    return false;
                }
                openning++;
            }
            pos = i+1;
        }

        return openning == 0;
    }
};