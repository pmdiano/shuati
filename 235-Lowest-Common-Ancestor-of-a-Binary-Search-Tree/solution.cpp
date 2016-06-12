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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return nullptr;
        }

        while (root) {
            if (max(p->val, q->val) < root->val) {
                root = root->left;
            } else if (min(p->val, q->val) > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }

        return nullptr;
    }
};