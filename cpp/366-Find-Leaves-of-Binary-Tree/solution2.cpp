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
    TreeNode* removeLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return nullptr;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return nullptr;
        }
        root->left = removeLeaves(root->left, leaves);
        root->right = removeLeaves(root->right, leaves);
        return root;
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> leaves;
            root = removeLeaves(root, leaves);
            res.push_back(leaves);
        }
        return res;
    }
};