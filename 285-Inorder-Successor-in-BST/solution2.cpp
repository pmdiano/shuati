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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *successor = nullptr;
        while (root && root->val != p->val) {
            if (root->val < p->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }

        if (!root) {
            return nullptr;
        }

        if (!root->right) {
            return successor;
        }

        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};