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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *odd = head, *p = odd;
        ListNode *even = head->next, *q = even;
        head = head->next->next;

        while (head && head->next) {
            p->next = head;
            q->next = head->next;
            head = head->next->next;
            p = p->next;
            q = q->next;
        }

        if (head) {
            p->next = head;
            p = p->next;
        }

        p->next = even;
        q->next = nullptr;
        return odd;
    }
};