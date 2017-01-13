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
    vector<int> dfs(TreeNode* root) {
        // [0]: not including root
        // [1]: including root
        if (!root) {
            return {0, 0};
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> res({0, 0});
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
        return res;
    }

public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};