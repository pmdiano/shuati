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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* node = head;

        while (node && node->next) {
            if (node->val != node->next->val) {
                node = node->next;
                prev = prev->next;
            } else {
                int val = node->val;
                while (node && node->val == val) {
                    ListNode* tmp = node->next;
                    delete node;
                    node = node->next;
                }
                prev->next = node;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};