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
    int minDepth(TreeNode* root) {
        int depth = 0;

        queue<TreeNode*> Q;
        if (root)
            Q.push(root);

        while (!Q.empty()) {
            depth++;

            int size = Q.size();
            while (size--) {
                TreeNode *node = Q.front();
                Q.pop();
                if (!node->left && !node->right)
                    return depth;

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
        }

        return depth;
    }
};