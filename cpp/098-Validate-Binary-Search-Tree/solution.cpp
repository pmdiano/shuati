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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode* prev = nullptr;

        while (root || !S.empty()) {
            if (root) {
                S.push(root);
                root = root->left;
            } else {
                if (prev && prev->val >= S.top()->val) {
                    return false;
                }

                prev = S.top();
                S.pop();
                root = prev->right;
            }
        }

        return true;
    }
};