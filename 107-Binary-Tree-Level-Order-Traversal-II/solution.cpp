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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> level;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            } else {
                if (!level.empty()) {
                    result.push_back(level);
                    level.clear();
                    q.push(nullptr);
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
