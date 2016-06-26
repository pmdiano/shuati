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

        ListNode *prev = head, *tail = head;
        while (n--) {
            tail = tail->next;
        }

        if (!tail) {
            // remove head
            ListNode *node = head->next;
            delete head;
            return node;
        }

        while (tail->next) {
            tail = tail->next;
            prev = prev->next;
        }
        ListNode *node = prev->next;
        prev->next = prev->next->next;
        delete node;
        return head;
    }
};