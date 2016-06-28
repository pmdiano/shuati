/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) {
            return;
        }

        ListNode* next = node->next;
        node->next = next->next;
        node->val = next->val;
        delete next;
    }
};