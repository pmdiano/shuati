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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* last = nullptr;

        while (root || !S.empty()) {
            if (root) {
                S.push(root);
                root = root->left;
            } else {
                TreeNode *node = S.top();
                if (node->right == nullptr || node->right == last) {
                    result.push_back(node->val);
                    S.pop();
                    last = node;
                } else {
                    root = node->right;
                }
            }
        }
        
        return result;
    }
};