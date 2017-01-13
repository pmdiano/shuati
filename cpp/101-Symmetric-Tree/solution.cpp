/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        return (p->val == q->val)
            && isMirror(p->left, q->right)
            && isMirror(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return isMirror(root->left, root->right);
    }
};
