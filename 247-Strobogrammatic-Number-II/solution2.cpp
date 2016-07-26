class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> one({"0", "1", "8"}), two({""}), res = two;
        if (n % 2 != 0) res = one;
        for (int i = (n%2)+2; i <= n; i+=2) {
            vector<string> t;
            for (auto& s : res) {
                if (i != n) t.push_back("0" + s + "0");
                t.push_back("1" + s + "1");
                t.push_back("6" + s + "9");
                t.push_back("8" + s + "8");
                t.push_back("9" + s + "6");
            }
            res = t;
        }
        return res;
    }
};