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
        // Note this is not O(1) space, this is still O(N) space.
        // O(1) space solution needs to use threaded binary tree.
        TreeNode *node1 = nullptr, *node2 = nullptr;
        TreeNode *dummy = new TreeNode(numeric_limits<int>::min());
        TreeNode *prev = dummy;
        stack<TreeNode*> s;

        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                if (node1 == nullptr && s.top()->val < prev->val) {
                    node1 = prev;
                }
                if (node1 != nullptr && s.top()->val < prev->val) {
                    node2 = s.top();
                }

                prev = s.top();
                s.pop();
                root = prev->right;
            }
        }

        swap(node1->val, node2->val);
        delete dummy;
    }
};
