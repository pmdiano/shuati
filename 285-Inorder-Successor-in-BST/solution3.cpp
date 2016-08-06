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
    TreeNode* minimum(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }

public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return nullptr;
        }

        if (p->right) {
            return minimum(p->right);
        }

        TreeNode* ancestor = nullptr;
        bool found = false;
        while (root) {
            if (root->val == p->val) {
                found = true;
                break;
            } else if (p->val < root->val) {
                ancestor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        if (!found) {
            return nullptr;
        }

        return ancestor;
    }
};