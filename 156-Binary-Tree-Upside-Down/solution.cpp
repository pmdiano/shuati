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
        if (!root) {
            return nullptr;
        }

        TreeNode* parent = nullptr, *side = nullptr, *temp = nullptr, *child = root;

        while (child) {
            temp = child->left;
            child->left = side;
            side = child->right;
            child->right = parent;
            parent = child;
            child = temp;
        }

        return parent;
    }
};
