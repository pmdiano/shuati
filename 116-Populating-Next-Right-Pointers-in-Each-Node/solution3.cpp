/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root && root->left) {
            TreeLinkNode *node = root;
            while (node) {
                node->left->next = node->right;
                node->right->next = node->next ? node->next->left : nullptr;
                node = node->next;
            }
            root = root->left;
        }
    }
};