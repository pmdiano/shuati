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
    void dfs(TreeNode* root, unordered_map<TreeNode*, int>& hash, int& longest) {
        if (root->left) {
            if (root->left->val == root->val + 1) {
                hash[root->left] = hash[root] + 1;
                longest = max(longest, hash[root->left]);
            } else {
                hash[root->left] = 1;
            }

            dfs(root->left, hash, longest);
        }

        if (root->right) {
            if (root->right->val == root->val + 1) {
                hash[root->right] = hash[root] + 1;
                longest = max(longest, hash[root->right]);
            } else {
                hash[root->right] = 1;
            }

            dfs(root->right, hash, longest);
        }
    }

public:
    int longestConsecutive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        unordered_map<TreeNode*, int> hash;
        hash[root] = 1;
        int longest = 1;

        dfs(root, hash, longest);

        return longest;
    }
};
