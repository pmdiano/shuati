/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    void setParent(TreeLinkNode *root) {
        if (root && root->left && root->right) {
            root->left->next = root;
            root->right->next = root;
            setParent(root->left);
            setParent(root->right);
        }
    }

    void setRight(TreeLinkNode *root) {
        if (!root) {
            return;
        }

        setRight(root->left);
        setRight(root->right);

        if (root->next && root->next->left == root) {
            root->next = root->next->right;
        } else {
            int d = 0;
            TreeLinkNode *node = root;
            while (node->next && node->next->right == node) {
                d++;
                node = node->next;
            }
            if (node->next) {
                node = node->next->right;
                while (d--) node = node->left;
                root->next = node;
            } else {
                root->next = nullptr;
            }
        }
    }
public:
    void connect(TreeLinkNode *root) {
        setParent(root);
        setRight(root);
    }
};