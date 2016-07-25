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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *p = root;
        int cnt = 0;
        while (cnt < k) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top(); stk.pop();
            if (++cnt == k) break;
            p = p->right;
        }
        return p->val;
    }
};