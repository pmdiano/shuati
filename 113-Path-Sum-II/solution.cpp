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
    void dfs(TreeNode* root, int sum, vector<int> &current, vector<vector<int>> &result) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right && root->val == sum) {
            current.push_back(root->val);
            result.push_back(current);
            current.pop_back();
            return;
        }

        current.push_back(root->val);
        dfs(root->left, sum - root->val, current, result);
        dfs(root->right, sum - root->val, current, result);
        current.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> current;
        vector<vector<int>> result;

        dfs(root, sum, current, result);
        return result;
    }
};
