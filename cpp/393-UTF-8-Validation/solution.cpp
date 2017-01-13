class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < n) {
            if (!(data[i] & 0x80)) {
                // One byte
                i++;
            } else {
                int len = 0;
                if ((data[i] & 0xE0) == 0xC0) {
                    len = 1;
                } else if ((data[i] & 0xF0) == 0xE0) {
                    len = 2;
                } else if ((data[i] & 0xF8) == 0xF0 ) {
                    len = 3;
                } else {
                    return false;
                }

                if (i + len >= n) {
                    return false;
                }
                i++;
                for (int j = 0; j < len; i++, j++) {
                    if ((data[i] & 0xC0) != 0x80) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};