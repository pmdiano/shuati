class Solution {
    char precede(char theta1, char theta2) {
        if (theta1 == '#')
            return theta2 == '#' ? '=' : '<';
        else if (theta1 == '(')
            return theta2 == ')' ? '=' : '<';
        else if (theta1 == '+' || theta1 == '-')
            return theta2 == '(' || theta2 == '*' || theta2 == '/' ? '<' : '>';
        else if (theta1 == '*' || theta1 == '/')
            return theta2 == '(' ? '<' : '>';
        else
            return '>';
    }

    int operate(int a, char theta, int b) {
        switch (theta) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
            default: return 0;
        }
    }

public:
    int calculate(string s) {
        stack<char> optr;
        stack<int> opnd;
        optr.push('#');
        s.push_back('#');

        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') { i++; continue; }
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) num = 10 * num + s[i++] - '0';
                opnd.push(num);
                continue;
            }
            switch(precede(optr.top(), s[i])) {
                case '<':
                    optr.push(s[i++]);
                    break;
                case '=':
                    optr.pop();
                    i++;
                    break;
                case '>':
                    char theta = optr.top(); optr.pop();
                    int b = opnd.top(); opnd.pop();
                    int a = opnd.top(); opnd.pop();
                    int c = operate(a, theta, b);
                    opnd.push(c);
                    break;
            }
        }

        return opnd.top();
    }
};