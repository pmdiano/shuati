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
    TreeNode* helper(int* inorder, int in_len, int* postorder, int post_len) {
        if (in_len == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[post_len-1]);

        for (int i = 0; i < in_len; i++) {
            if (inorder[i] == root->val) {
                const int left_len = i;
                const int right_len = in_len-i-1;

                root->left = helper(inorder, left_len, postorder, left_len);
                root->right = helper(inorder+i+1, right_len, postorder+left_len, right_len);

                break;
            }
        }

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return nullptr;
        }

        return helper(&inorder[0], inorder.size(), &postorder[0], postorder.size());
    }
};
