class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0, i = 0;
        stack<int> stk;
        stk.push(0);
        input.push_back('\n');

        while (input[i]) {
            int depth = 0;
            while (input[i] == '\t') { depth++; i++; }
            while (depth < (int)stk.size()-1) stk.pop();

            bool has_dot = false;
            int j = i;
            while (input[i] != '\n') {
                if (input[i++] == '.') has_dot = true;
            }

            if (has_dot) {
                res = max(res, stk.top()+i-j);
            } else {
                stk.push(stk.top()+i-j+1);
            }

            i++;
        }

        return res;
    }
};
