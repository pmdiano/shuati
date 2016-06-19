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
        TreeNode *lower = nullptr, *upper = nullptr;
        while (root) {
            if (target < root->val) {
                upper = root;
                root = root->left;
            } else {
                lower = root;
                root = root->right;
            }
        }

        if (lower && upper) {
            return (upper->val - target < target - lower->val ? upper->val : lower->val);
        } else if (lower) {
            return lower->val;
        } else if (upper) {
            return upper->val;
        } else {
            return 0;
        }
    }
};
