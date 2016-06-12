/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> S;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            S.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = S.top();
        S.pop();

        TreeNode* node = top->right;
        while (node) {
            S.push(node);
            node = node->left;
        }

        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */