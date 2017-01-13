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
        stack<TreeNode*> s;
        TreeNode* last = nullptr;

        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                if (root->right && root->right != last) {
                    root = root->right;
                } else {
                    s.pop();
                    res.push_back(root->val);
                    last = root;
                    root = nullptr;
                }
            }
        }

        return res;
    }
};