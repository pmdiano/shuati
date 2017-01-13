class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) {
            return vector<int>();
        }

        int total = pow(2, n);
        vector<int> result(total, 0);
        unordered_set<int> sofar;
        sofar.insert(0);

        for (int i = 1; i < total; i++) {
            int mask = 1;
            for (;;) {
                int a = result[i-1] ^ mask;
                if (sofar.find(a) == sofar.end()) {
                    sofar.insert(a);
                    result[i] = a;
                    break;
                }
                mask <<= 1;
            }
        }

        return result;
    }
};