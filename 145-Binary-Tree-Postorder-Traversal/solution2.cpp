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
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* last = nullptr;

        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                if (!root->right || root->right == last) {
                    stk.pop();
                    res.push_back(root->val);
                    last = root;
                    root = nullptr;
                } else {
                    root = root->right;
                }
            }
        }

        return res;
    }
};