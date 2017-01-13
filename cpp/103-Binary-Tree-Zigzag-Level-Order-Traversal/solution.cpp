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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        bool flip = false;
        if (root) {
            Q.push(root);
        }

        while (!Q.empty()) {
            vector<int> level;
            int size = Q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                level.push_back(node->val);

                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }

            if (flip) {
                reverse(level.begin(), level.end());
            }
            result.push_back(level);
            flip = !flip;
        }

        return result;
    }
};
