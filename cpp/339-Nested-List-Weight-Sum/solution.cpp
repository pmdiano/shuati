/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        stack<pair<const NestedInteger*, int>> s;
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            s.push(make_pair(&nestedList[i], 1));
        }

        while (!s.empty()) {
            auto node = s.top(); s.pop();
            if (node.first->isInteger()) {
                sum += node.first->getInteger() * node.second;
            } else {
                const vector<NestedInteger>& list = node.first->getList();
                for (int i = list.size() - 1; i >= 0; i--) {
                    s.push(make_pair(&list[i], node.second + 1));
                }
            }
        }

        return sum;
    }
};