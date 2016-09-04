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
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &hash) {
        if (!root) {
            return 0;
        }
        if (hash.count(root)) {
            return hash[root];
        }

        int val = 0;
        if (root->left) {
            val += dfs(root->left->left, hash) + dfs(root->left->right, hash);
        }
        if (root->right) {
            val += dfs(root->right->left, hash) + dfs(root->right->right, hash);
        }

        hash[root] = max(root->val + val, dfs(root->left, hash) + dfs(root->right, hash));
        return hash[root];
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> hash;
        return dfs(root, hash);
    }
};