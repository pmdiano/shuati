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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> S;

        while (root || !S.empty()) {
            if (root) {
                S.push(root);
                root = root->left;
            } else {
                root = S.top();
                S.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }

        return result;
    }
};