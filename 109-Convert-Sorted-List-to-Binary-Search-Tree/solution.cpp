/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* construct(ListNode*& head, int n) {
        if (n == 0) {
            return nullptr;
        }

        TreeNode* left = construct(head, n/2);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = construct(head, n-n/2-1);

        root->left = left;
        root->right = right;
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for (ListNode* node = head; node; node = node->next, n++);
        return construct(head, n);
    }
};