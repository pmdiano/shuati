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
    void dfs(TreeNode* root, int current, int& longest) {
        longest = max(longest, current);

        if (root->left) {
            dfs(root->left, root->left->val == root->val+1 ? current+1 : 1, longest);
        }

        if (root->right) {
            dfs(root->right, root->right->val == root->val+1 ? current+1 : 1, longest);
        }
    }

public:
    int longestConsecutive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int longest = 1;
        dfs(root, 1, longest);

        return longest;
    }
};
