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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* node = head->next;
        ListNode* prev = head;
        while (node) {
            if (node->val == prev->val) {
                prev->next = node->next;
                delete node;
                node = prev->next;
            } else {
                node = node->next;
                prev = prev->next;
            }
        }

        return head;
    }
};