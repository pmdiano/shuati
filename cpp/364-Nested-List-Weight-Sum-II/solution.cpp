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
    int getDepth(NestedInteger& root) {
        if (root.isInteger()) {
            return 1;
        }

        int depth = 0;
        for (auto child : root.getList()) {
            depth = max(depth, getDepth(child) + 1);
        }

        return depth;
    }

    int dfs(NestedInteger& root, int depth) {
        if (root.isInteger()) {
            return root.getInteger() * depth;
        }

        int sum = 0;
        for (auto child : root.getList()) {
            sum += dfs(child, depth - 1);
        }

        return sum;
    }

public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 0;
        for (auto child : nestedList) {
            depth = max(depth, getDepth(child));
        }

        int sum = 0;
        for (auto child : nestedList) {
            sum += dfs(child, depth);
        }

        return sum;
    }
};