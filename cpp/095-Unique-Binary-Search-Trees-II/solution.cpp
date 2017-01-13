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
    TreeNode* clone(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        TreeNode* root2 = new TreeNode(root->val);
        root2->left = clone(root->left);
        root2->right = clone(root->right);

        return root2;
    }

    void clear(TreeNode* root) {
        if (!root) {
            return;
        }

        clear(root->left);
        clear(root->right);
        delete root;
    }

    vector<TreeNode*> helper(int n1, int n2) {
        if (n1 > n2) {
            return vector<TreeNode*>(1, nullptr);
        }

        if (n1 == n2) {
            return vector<TreeNode*>(1, new TreeNode(n1));
        }

        vector<TreeNode*> result;
        for (int n = n1; n <= n2; n++) {
            vector<TreeNode*> left = helper(n1, n-1);
            vector<TreeNode*> right = helper(n+1, n2);

            for (auto leftRoot : left) {
                for (auto rightRoot : right) {
                    TreeNode* root = new TreeNode(n);
                    root->left = clone(leftRoot);
                    root->right = clone(rightRoot);
                    result.push_back(root);
                }
            }

            for (auto leftRoot : left) {
                clear(leftRoot);
            }
            for (auto rightRoot : right) {
                clear(rightRoot);
            }
        }

        return result;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return vector<TreeNode*>();
        }

        return helper(1, n);
    }
};
