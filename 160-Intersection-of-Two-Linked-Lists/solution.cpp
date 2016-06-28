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
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode *p = headA, *q = headB;
        int lenA = 1, lenB = 1;
        while (p->next) { p = p->next; lenA++; }
        while (q->next) { q = q->next; lenB++; }
        if (p != q) {
            return nullptr;
        }

        headA = reverse(headA);
        q = headB;
        int lenBnew = 0;
        while (q) { q = q->next; lenBnew++; }

        int a = (lenA -lenB + lenBnew - 1) / 2;
        p = reverse(headA);
        while (a--) {
            p = p->next;
        }

        return p;
    }
};