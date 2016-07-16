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
        while (root) {
            TreeLinkNode *node = root, *first = nullptr, *prev = nullptr;
            while (node) {
                if (node->left) {
                    if (!first) {
                        first = node->left;
                        prev = node->left;
                    } else {
                        prev->next = node->left;
                        prev = prev->next;
                    }
                }
                if (node->right) {
                    if (!first) {
                        first = node->right;
                        prev = node->right;
                    } else {
                        prev->next = node->right;
                        prev = prev->next;
                    }
                }
                node = node->next;
            }
            root = first;
        }
    }
};