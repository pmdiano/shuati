/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseBetween(ListNode* start, ListNode* end) {
        ListNode *prev = start, *node = start->next, *temp;
        while (node != end) {
            temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        temp = start->next;
        temp->next = end;
        start->next = prev;
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 0) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy, *end = dummy;

        for (;;) {
            int n = 0;
            while (end && n++ < k) {
                end = end->next;
            }
            if (!end) {
                break;
            }
            start = reverseBetween(start, end->next);
            end = start;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};