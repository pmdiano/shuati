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
    int count(TreeNode* root) {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;

        int left = count(root->left);
        if (left == k-1)
            return root->val;
        else if (left < k-1)
            return kthSmallest(root->right, k-left-1);
        else
            return kthSmallest(root->left, k);
    }
};