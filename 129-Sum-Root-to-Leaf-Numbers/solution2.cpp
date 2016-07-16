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
    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        TreeNode* last = nullptr;
        stack<TreeNode*> stk;

        while (root || !stk.empty()) {
            if (root) {
                num = 10*num + root->val;
                stk.push(root);
                root = root->left;
            } else {
                TreeNode* node = stk.top();
                if (node->right && node->right != last) {
                    root = node->right;
                } else {
                    if (!node->left && !node->right) {
                        sum += num;
                    }
                    last = node;
                    stk.pop();
                    num /= 10;
                }
            }
        }

        return sum;
    }
};