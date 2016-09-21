/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int getInt(string &s, int &pos) {
        // pos will change to the first char after this integer
        int sign = s[pos] == '-' ? -1 : 1;
        if (sign == -1) pos++;
        int res = 0;
        while (isdigit(s[pos])) {
            res *= 10;
            res += (s[pos] - '0');
            pos++;
        }
        return sign == -1 ? -res : res;
    }

public:
    NestedInteger deserialize(string s) {
        int i = 0;
        stack<NestedInteger> stk;
        NestedInteger curr;
        while (i < s.size()) {
            switch (s[i]) {
                case ',':
                    i++;
                    break;

                case '[':
                    stk.push(curr);
                    curr = NestedInteger();
                    i++;
                    break;

                case ']':
                    stk.top().add(curr);
                    curr = stk.top();
                    stk.pop();
                    i++;
                    break;

                default:
                    NestedInteger val(getInt(s, i));
                    curr.add(val);
                    break;
            }
        }

        return curr.getList()[0];
    }
};