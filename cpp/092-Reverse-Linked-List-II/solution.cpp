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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;

        int i = 1;
        while (i < m) {
            prev = prev->next;
            i++;
        }

        ListNode* p = prev;
        ListNode* node = prev->next;
        while (i <= n) {
            ListNode* next = node->next;
            node->next = p;
            p = node;
            node = next;
            i++;
        }
        prev->next->next = node;
        prev->next = p;

        head = dummy->next;
        delete dummy;
        return head;
    }
};