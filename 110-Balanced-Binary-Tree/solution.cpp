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
    bool dfs(TreeNode* root, int* height) {
        if (!root) {
            *height = 0;
            return true;
        }
        
        int leftHeight = 0;
        int rightHeight = 0;
        
        if (!dfs(root->left, &leftHeight) || !dfs(root->right, &rightHeight)) {
            return false;
        } else {
            *height = max(leftHeight, rightHeight) + 1;
            return abs(leftHeight - rightHeight) <= 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, &height);
    }
};