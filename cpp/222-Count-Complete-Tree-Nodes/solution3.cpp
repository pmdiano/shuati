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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int h = 0, count = 0;
        TreeNode* p = root, *q;
        while (p) {
            p = p->left;
            h++;
        }

        p = root;
        for (int level = h-2; level >= 0; level--) {
            q = p->left;
            for (int i = 0; i < level; i++) {
                q = q->right;
            }

            if (q) {
                count += 1 << level;
                p = p->right;
            } else {
                p = p->left;
            }
        }
        if (p) count++;

        return count + (1 << (h-1)) - 1;
    }
};