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
    struct FlatternResult {
        TreeNode* head;
        TreeNode* tail;
        FlatternResult(): head(nullptr), tail(nullptr) {}
        FlatternResult(TreeNode* h, TreeNode* t): head(h), tail(t) {}
    };

    // Return last node
    FlatternResult dfs(TreeNode* root) {
        if (!root) {
            return FlatternResult(nullptr, nullptr);
        }

        FlatternResult left = dfs(root->left);
        FlatternResult right = dfs(root->right);

        TreeNode* tail = root;
        root->left = nullptr;

        if (left.head) {
            root->right = left.head;
            tail = left.tail;
        }
        if (right.head) {
            tail->right = right.head;
            tail = right.tail;
        }

        return FlatternResult(root, tail);
    }
public:
    void flatten(TreeNode* root) {
        (void)dfs(root);
    }
};