class Solution {
    void helper(string& num, int pos, int target, long currRes, long prevNum, string path, vector<string>& ans) {
        if (pos == num.length() && currRes == target) {
            ans.push_back(path);
        }

        for (int i = pos+1; i <= num.length(); i++) {
            string currStr = num.substr(pos, i-pos);
            if (currStr.length() > 1 && currStr[0] == '0') {
                return;
            }

            long currNum = stol(currStr);
            if (!path.empty()) {
                helper(num, i, target, currRes + currNum, currNum, path + "+" + currStr, ans);
                helper(num, i, target, currRes - currNum, -currNum, path + "-" + currStr, ans);
                helper(num, i, target, currRes - prevNum + prevNum * currNum, prevNum * currNum, path + "*" + currStr, ans);
            } else {
                helper(num, i, target, currNum, currNum, currStr, ans);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, 0, target, 0, 0, "", ans);
        return ans;
    }
};