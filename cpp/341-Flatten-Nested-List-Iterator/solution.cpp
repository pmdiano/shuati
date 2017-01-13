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
class NestedIterator {
    struct Node {
        const NestedInteger& nestedInteger;
        int index;
        Node(const NestedInteger& ni, int i): nestedInteger(ni), index(i) {}
    };

    stack<Node> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            s.push(Node(nestedList[i], 0));
        }
    }

    int next() {
        int next = s.top().nestedInteger.getInteger();
        s.pop();
        return next;
    }

    bool hasNext() {
        while (!s.empty() && !s.top().nestedInteger.isInteger()) {
            if (s.top().index == s.top().nestedInteger.getList().size()) {
                s.pop();
            } else {
                s.push(Node(s.top().nestedInteger.getList()[s.top().index++], 0));
            }
        }
        
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */