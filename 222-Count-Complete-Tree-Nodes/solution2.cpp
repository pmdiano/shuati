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
    int getHeight(TreeNode* root) {
        int h = 0;
        while (root) root = root->left, h++;
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if (lh == rh) {
            return (1 << lh) + countNodes(root->right);
        } else {
            return (1 << rh) + countNodes(root->left);
        }
    }
};