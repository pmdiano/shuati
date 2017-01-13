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
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void removeLeaves(TreeNode* root, vector<int> &leaves) {
        if (!root) return;

        if (isLeaf(root->left)) {
            leaves.push_back(root->left->val);
            delete root->left;
            root->left = nullptr;
        } else {
            removeLeaves(root->left, leaves);
        }

        if (isLeaf(root->right)) {
            leaves.push_back(root->right->val);
            delete root->right;
            root->right = nullptr;
        } else {
            removeLeaves(root->right, leaves);
        }
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root && !isLeaf(root)) {
            vector<int> leaves;
            removeLeaves(root, leaves);
            res.push_back(leaves);
        }
        if (isLeaf(root)) {
            res.push_back(vector<int>(1, root->val));
        }
        return res;
    }
};