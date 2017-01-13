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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = head;

        while (p->next) {
            ListNode* q = dummy;
            while (q != p && q->next->val <= p->next->val) {
                q = q->next;
            }

            if (q == p) {
                p = p->next;
            } else {
                ListNode* node = p->next;
                p->next = p->next->next;

                node->next = q->next;
                q->next = node;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};