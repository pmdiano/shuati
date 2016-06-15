/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> range;
        if (!root || k1 > k2) {
            return range;
        }

        stack<TreeNode*> s;
        while (root) {
            if (root->val >= k1) {
                s.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node->val > k2) {
                break;
            }

            range.push_back(node->val);
            node = node->right;
            while (node) {
                s.push(node);
                node = node->left;
            }
        }

        return range;
    }
};
