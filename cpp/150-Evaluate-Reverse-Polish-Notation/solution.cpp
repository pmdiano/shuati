class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for (string& t : tokens) {
            if (t.length() > 1 || isdigit(t[0])) {
                operands.push(atoi(t.c_str()));
            } else {
                int o2 = operands.top(); operands.pop();
                int o1 = operands.top(); operands.pop();
                int o = 0;
                switch (t[0]) {
                    case '+':
                        o = o1 + o2;
                        break;
                    case '-':
                        o = o1 - o2;
                        break;
                    case '*':
                        o = o1 * o2;
                        break;
                    case '/':
                        o = o1 / o2;
                        break;
                }
                operands.push(o);
            }
        }
        return operands.top();
    }
};