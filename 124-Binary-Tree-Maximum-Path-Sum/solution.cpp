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
    int dfs(TreeNode* root, int *maxRootPath) {
        if (!root) {
            *maxRootPath = 0;
            return numeric_limits<int>::min();
        }
        
        if (!root->left && !root->right) {
            *maxRootPath = root->val;
            return root->val;
        }

        int leftRootPath = 0, rightRootPath = 0;
        int leftMaxPath = dfs(root->left, &leftRootPath);
        int rightMaxPath = dfs(root->right, &rightRootPath);

        *maxRootPath = max(max(leftRootPath, rightRootPath), 0) + root->val;

        int maxPath = max(leftMaxPath, rightMaxPath);
        maxPath = max(maxPath, leftRootPath + rightRootPath + root->val);
        return max(maxPath, *maxRootPath);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxRootPath = 0;
        return dfs(root, &maxRootPath);
    }
};