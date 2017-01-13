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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) {
            return root;
        }

        TreeNode *node = upsideDownBinaryTree(root->left);

        root->left->right = root;
        root->left->left = root->right;
        root->left = nullptr;
        root->right = nullptr;

        return node;
    }
};
