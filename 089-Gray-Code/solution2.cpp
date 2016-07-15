class Solution {
    // http://bangbingsyb.blogspot.com/2014/11/leetcode-gray-code.html
public:
    vector<int> grayCode(int n) {
        vector<int> graySeq;
        if (n < 0) {
            return graySeq;
        }

        graySeq.reserve(1 << n);
        graySeq.push_back(0);

        int inc = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = graySeq.size() - 1; j >= 0; j--) {
                graySeq.push_back(graySeq[j] + inc);
            }
            inc <<= 1;
        }

        return graySeq;
    }
};