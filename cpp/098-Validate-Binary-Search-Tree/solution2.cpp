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
    bool isValidBST(TreeNode* root) {
        return isValid(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (!root) {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return isValid(root->left, minVal, root->val)
            && isValid(root->right, root->val, maxVal);
    }
};