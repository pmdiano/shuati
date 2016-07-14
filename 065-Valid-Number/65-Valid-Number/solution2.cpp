class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };

        const int transitionTable[][NUM_INPUTS] = {
            /*
            invalid space   sign    digit   dot     exp
            */
            -1,     0,      3,      1,      2,      -1,     // #0 no input or just spaces
            -1,     8,      -1,     1,      4,      5,      // #1 input is digits
            -1,     -1,     -1,     4,      -1,     -1,     // #2 no digits in front, just dot
            -1,     -1,     -1,     1,      2,      -1,     // #3 sign
            -1,     8,      -1,     4,      -1,     5,      // #4 digits and dot in front
            -1,     -1,     6,      7,      -1,     -1,     // #5 input 'e'
            -1,     -1,     -1,     7,      -1,     -1,     // #6 after 'e', input sign
            -1,     8,      -1,     7,      -1,     -1,     // #7 after 'e', input digits
            -1,     8,      -1,     -1,     -1,     -1      // #8 after valid input, input space
        };

        int state = 0;
        for (int i = 0; i < s.length(); i++) {
            InputType inputType = INVALID;
            if (isspace(s[i]))
                inputType = SPACE;
            else if (s[i] == '+' || s[i] == '-')
                inputType = SIGN;
            else if (isdigit(s[i]))
                inputType = DIGIT;
            else if (s[i] == '.')
                inputType = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];
            if (state == -1) {
                return false;
            }
        }

        return (state == 1 || state == 4 || state == 7 || state == 8);
    }
};