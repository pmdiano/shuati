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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || !head) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *tail = head;

        while (n--) {
            tail = tail->next;
        }
        while (tail) {
            tail = tail->next;
            prev = prev->next;
        }

        ListNode *node = prev->next;
        prev->next = node->next;

        head = dummy->next;
        delete dummy;
        delete node;

        return head;
    }
};