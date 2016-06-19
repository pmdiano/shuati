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
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *cur = root;
        TreeNode *f1 = nullptr, *f2 = nullptr;
        TreeNode *last = nullptr;

        while (cur) {
            if (!cur->left) {
                // visit cur here
                if (last && last->val > cur->val) {
                    if (!f1) {
                        f1 = last;
                    }
                    f2 = cur;
                }
                last = cur;

                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // visite cur here
                    if (last->val > cur->val) {
                        if (!f1) {
                            f1 = last;
                        }
                        f2 = cur;
                    }
                    last = cur;

                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        if (f1 && f2) {
            swap(f1->val, f2->val);
        }
    }
};