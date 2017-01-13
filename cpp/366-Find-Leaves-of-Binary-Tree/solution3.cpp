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
    int helper(TreeNode* node, vector<vector<int>> &res) {
        if (!node) return -1;
        int depth = 1 + max(helper(node->left, res), helper(node->right, res));
        if (depth >= res.size()) res.resize(depth+1);
        res[depth].push_back(node->val);
        return depth;
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
};