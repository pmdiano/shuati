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
    TreeNode* helper(int* preorder, int pre_len, int* inorder, int in_len) {
        if (pre_len == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 0; i < in_len; i++) {
            if (inorder[i] == preorder[0]) {
                const int left_len = i;
                const int right_len = in_len - left_len - 1;

                root->left = helper(preorder+1, left_len, inorder, left_len);
                root->right = helper(preorder+1+left_len, right_len, inorder+1+left_len, right_len);

                break;
            }
        }

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) {
            return nullptr;
        }

        return helper(&preorder[0], preorder.size(), &inorder[0], inorder.size());
    }
};