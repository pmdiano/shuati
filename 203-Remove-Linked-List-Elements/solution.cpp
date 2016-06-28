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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        dummy->next = head;

        while (p->next) {
            if (p->next->val == val) {
                ListNode* node = p->next;
                p->next = p->next->next;
                delete node;
            } else {
                p = p->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};