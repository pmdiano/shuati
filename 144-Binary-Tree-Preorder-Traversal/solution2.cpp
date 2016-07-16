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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        
        while (root || !stk.empty()) {
            while (root) {
                result.push_back(root->val);
                stk.push(root->right);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
        }
        
        return result;
    }
};