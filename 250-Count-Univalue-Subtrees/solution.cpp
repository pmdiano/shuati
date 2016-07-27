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
    bool helper(TreeNode* root, int& count) {
        if (!root) return true;
        bool leftOk = helper(root->left, count);
        bool rightOk = helper(root->right, count);
        if (leftOk && (!root->left || root->left->val == root->val)) {
            if (rightOk && (!root->right || root->right->val == root->val)) {
                count++;
                return true;
            }
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
};