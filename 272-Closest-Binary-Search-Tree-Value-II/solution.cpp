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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if (!root || k <= 0) {
            return vector<int>();
        }

        queue<int> q;
        stack<TreeNode*> s;

        // Push first k elements of inorder traversal to the queue
        while (q.size() < k) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                q.push(root->val);
                root = root->right;
            }
        }

        // Inorder traverse
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();

                if (abs(root->val - target) < abs(q.front() - target)) {
                    q.pop();
                    q.push(root->val);
                } else {
                    break;
                }

                root = root->right;
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};