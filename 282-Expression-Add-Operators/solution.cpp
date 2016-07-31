class Solution {
    void dfs(string& num, int pos, int target, long long sumSoFar, long long product, long long lastNum, int sign, string path, vector<string>& result) {
        long long currNum = lastNum * 10 + num[pos] - '0';
        if (pos == num.length() - 1) {
            if (sumSoFar + product * currNum * sign == target) {
                result.push_back(path + num[pos]);
            }
            return;
        }

        dfs(num, pos+1, target, sumSoFar + product * currNum * sign, 1, 0, 1, path + num[pos] + "+", result); // +
        dfs(num, pos+1, target, sumSoFar + product * currNum * sign, 1, 0, -1, path + num[pos] + "-", result);// -
        dfs(num, pos+1, target, sumSoFar, product * currNum, 0, sign, path + num[pos] + "*", result); // *
        if (currNum != 0) dfs(num, pos+1, target, sumSoFar, product, currNum, sign, path + num[pos], result);
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) {
            return result;
        }

        dfs(num, 0, target, 0, 1, 0, 1, "", result);
        return result;
    }
};