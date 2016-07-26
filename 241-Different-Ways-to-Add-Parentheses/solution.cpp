class Solution {
    inline int calculate(int left, int right, char op) {
        switch (op) {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            default: return 0;
        }
    }

    vector<int> helper(string& input, int start, int end) {
        vector<int> ret;

        for (int i = start; i <= end; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = helper(input, start, i-1);
                vector<int> right = helper(input, i+1, end);
                for (int l : left) {
                    for (int r : right) {
                        ret.push_back(calculate(l, r, input[i]));
                    }
                }
            }
        }

        if (ret.empty()) {
            int num = 0;
            for (int i = start; i <= end; i++) {
                num = 10 * num + (input[i] - '0');
            }
            ret.push_back(num);
        }

        return ret;
    }

public:
    vector<int> diffWaysToCompute(string input) {
        return helper(input, 0, input.size()-1);
    }
};