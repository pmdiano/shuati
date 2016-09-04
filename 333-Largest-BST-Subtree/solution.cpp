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
    struct Result {
        bool isBst;
        int minVal;
        int maxVal;
        int maxBstNodes;
    };

    Result helper(TreeNode* root) {
        Result res;
        if (!root) {
            res.isBst = true;
            res.maxBstNodes = 0;
            return res;
        }

        Result left = helper(root->left);
        Result right = helper(root->right);

        if (left.isBst && right.isBst &&
            (!root->left || left.maxVal < root->val) &&
            (!root->right || right.minVal > root->val)) {
            res.isBst = true;
            res.minVal = root->left ? left.minVal : root->val;
            res.maxVal = root->right ? right.maxVal : root->val;
            res.maxBstNodes = left.maxBstNodes + right.maxBstNodes + 1;
            return res;
        }

        res.isBst = false;
        res.maxBstNodes = max(left.maxBstNodes, right.maxBstNodes);
        return res;
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).maxBstNodes;
    }
};