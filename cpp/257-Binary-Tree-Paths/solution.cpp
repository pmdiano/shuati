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
    void dfs(TreeNode* root, string& current, vector<string>& result) {
        if (!root) {
            return;
        }

        const string val = "->" + to_string(root->val);
        current += val;
        if (!root->left && !root->right) {
            result.push_back(current.substr(2));
        }

        dfs(root->left, current, result);
        dfs(root->right, current, result);

        current = current.substr(0, current.length() - val.length());
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string current = "";
        vector<string> result;

        dfs(root, current, result);

        return result;
    }
};
