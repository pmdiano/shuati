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
    void dfs(TreeNode* root, int num, int& sum) {
        num = 10 * num + root->val;
        if (!root->left && !root->right)
            sum += num;
            return;
        }

        if (root->left) {
            dfs(root->left, num, sum);
        }
        if (root->right) {
            dfs(root->right, num, sum);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        int num = 0, sum = 0;
        if (root) {
            dfs(root, num, sum);
        }
        return sum;
    }
};