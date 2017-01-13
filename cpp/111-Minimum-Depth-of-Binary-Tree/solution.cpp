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
    int dfs(TreeNode* root) {
        if (!root)
            return 0x7FFFFFFF;
        if (!root->left && !root->right)
            return 1;

        int l = dfs(root->left);
        int r = dfs(root->right);
        return min(l, r) + 1;
    }

public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        return dfs(root);
    }
};