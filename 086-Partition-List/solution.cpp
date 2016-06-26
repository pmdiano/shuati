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
    ListNode* partition(ListNode* head, int x) {
        ListNode* phead = new ListNode(0);
        ListNode* qhead = new ListNode(0);
        ListNode* p = phead;
        ListNode* q = qhead;

        while (head) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }

        p->next = qhead->next;
        q->next = nullptr;
        head = phead->next;
        delete phead;
        delete qhead;
        return head;
    }
};