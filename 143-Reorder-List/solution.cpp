/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    void combine(ListNode* head1, ListNode* head2) {
        ListNode* p = head1;
        head1 = head1->next;

        while (head1 && head2) {
            ListNode* t1 = head1->next;
            ListNode* t2 = head2->next;

            p->next = head2;
            p = p->next;
            p->next = head1;
            p = p->next;

            head1 = t1;
            head2 = t2;
        }

        if (head1) {
            p->next = head1;
        } else {
            p->next = head2;
        }
    }

public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        ListNode* p = head;
        ListNode* q = head->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }

        q = p->next;
        p->next = nullptr;
        combine(head, reverse(q));
    }
};