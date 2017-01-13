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
    int closestValue(TreeNode* root, double target) {
        if (!root) {
            return 0;
        }

        int closest = root->val;
        while (root) {
            if (abs(root->val - target) < abs(closest - target)) {
                closest = root->val;
            }

            if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return closest;
    }
};
