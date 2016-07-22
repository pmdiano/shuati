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
    bool exists(TreeNode* root, int h, int n) {
        if (h == 0) {
            return !!root;
        }

        int mask = 1 << (h-1);
        n--;
        while (root && mask) {
            if (mask & n) {
                root = root->right;
            } else {
                root = root->left;
            }
            mask >>= 1;
        }
        return !!root;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int h = 0;
        TreeNode* node = root->left;
        while (node) {
            node = node->left;
            h++;
        }

        int start = 1, end = 1 << h;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (exists(root, h, mid)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return (1 << h) - 1 + end;
    }
};